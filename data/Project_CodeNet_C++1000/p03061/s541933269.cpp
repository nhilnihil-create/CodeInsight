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
template <typename Monoid>
struct SegmentTree{

  int N;
  vector<Monoid> node;
  Monoid Unit;
  function<Monoid(Monoid, Monoid)> f;

  SegmentTree(vector<Monoid> v, const function<Monoid(Monoid, Monoid)> f, const Monoid &Unit): f(f), Unit(Unit){
    int sz_ = v.size();
    N = 1;
    while(N < sz_) N *= 2;

    node.assign(2*N, Unit);
    for(int i=0; i<sz_; i++) node[i+N-1] = v[i];
    for(int i=N-2; i>=0; i--) node[i] = f(node[2*i+1], node[2*i+2]);
  }

  void update(int k, const Monoid &x) {
    k += N-1;
    node[k] = x;
    while(k > 0){
      k = (k-1)/2;
      node[k] = f(node[2*k+1], node[2*k+2]);
    }
  }

  Monoid query(int a, int b, int k=0, int l = 0, int r=-1){
    if(r < 0) r = N;
    if(r <= a || b <= l) return Unit;
    
    if(a <= l && r <= b) return node[k];
    else{

      Monoid vl = query(a, b, 2*k+1, l, (l+r)/2);
      Monoid vr = query(a, b, 2*k+2, (l+r)/2, r);
      return f(vl, vr);
    }
  }
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
  function<int(int,int)> op = [&op](int a, int b){ return (b==0)?a:op(b,a%b);};
  SegmentTree<int> seg(a, op, 0);

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