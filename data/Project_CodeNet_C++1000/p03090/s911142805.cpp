// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << " = " << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define SP << " " <<

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;

const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> inline T ceil(T a, T b) {return T((a + b - 1) / b);}
template<class T> inline T round(T a, T b) {return T(a / b);}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }
template <class T> inline void out(T &a) { bool flag=true; for(auto&x:a){if(flag) {flag=false;} else{ cout << ' '; } cout<<x; } cout << endl; }



//----------------------------------------------------------------
int nmax=200000; // 2*(10^5)
vvec g(nmax);



struct UnionFind {
  private:
  vector<int> child,tree;
  vector<vector<int>> list;

public:
  UnionFind(int v) {
    tree.resize(v);
    list.resize(v);
    REP(i,v) tree[i] = i, list[i].push_back(i);
  }

  int root(int i){
    if(i == tree[i]){
      REP(j,child.size()) tree[child[j]] = i;
      child.clear(); 
      return i;
    }
    else{
      child.push_back(i);
      return i = root(tree[i]);
    }
  }

  int size(int i){
    return list[root(i)].size();
  }

  vector<int> nodes(int no){
    return list[root(no)];
  }

  bool unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    if(list[x].size() < list[y].size()) swap(x,y);
    for(int no:list[y]) list[x].emplace_back(no);
    tree[y] = x;
    return true;
  }

  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

void solve4ts()
{
    
    int n;
    cin>>n;
    UnionFind uf(n+1);
    if(n%2==1){
        for(int i=1;i<n;i++){
            uf.unit(i,n-i);
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(!uf.isUnit(i,j))cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(!uf.isUnit(i,j))cout<<i SP j<<"\n";
            }
        }
    }
    else{
        for(int i=1;i<n;i++){
            uf.unit(i,n+1-i);
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(!uf.isUnit(i,j))cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(!uf.isUnit(i,j))cout<<i SP j<<"\n";
            }
        }
    }
    
}
//-----------------------------------------------------------------

signed main(){ ios::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(15);
    int repeat = 1;
    // cin >> repeat;
    while(repeat--) solve4ts();
}