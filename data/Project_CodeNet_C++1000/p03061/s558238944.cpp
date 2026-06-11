#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

//ここから編集
template<typename T>
struct SegmentTree{

  vector<T> node;
  int n0;
  SegmentTree(vector<T>& v){
    int n = v.size();
    n0 = 1;
    while(n0 < n) n0 <<= 1;
    node.assign(2*n0,0);

    for(int i=0; i<n; i++) node[i+n0-1] = v[i];
    for(int i=n0-2; i>=0; i--) node[i] = GCD(node[i*2+1], node[i*2+2]);
  }

  void update(int k, T x){
    k += n0-1;
    node[k] = x;

    while(k > 0){
      k = (k-1)/2;
      node[k] = GCD(node[k*2+1], node[k*2+2]);
    }
  }

  T query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return 0;
    
    if(a <= l && r <= b) return node[k];
    else{

      T vl = query(a, b, 2*k+1, l, (l+r)/2);
      T vr = query(a, b, 2*k+2, (l+r)/2, r);
      return GCD(vl, vr);
    }
  
  }

  T query(int l, int r){
    return query(l, r, 0, 0, n0);
  }
  
  T GCD(T a, T b){ return (b == 0)?a:GCD(b, a%b); }
};

int GCD(int a, int b){
  if(b == 0) return a;
  return GCD(b, a%b);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(5);
  

  int N; cin >> N;
  vector<int> a(N);
  REP(i,N) cin >> a[i];
  SegmentTree<int> seg(a);

  int ans = 1;
  for(int i=0; i<N; i++){
    if(i == 0){
      ans = max(ans, seg.query(1, N));
    }else if(i == N-1){
      ans = max(ans, seg.query(0, i));
    }else{
      
      ans = max(ans, GCD(seg.query(0, i), seg.query(i+1, N)));
    }
  }
  cout << ans << endl;
  return 0;
}