#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

struct UnionFind{
  // 小さい方を大きいほうにくっつける
  // これのおかげでO(logN)になる
  // 親をたどる際に途中経路に結果を残しておくことで根に直接葉をつなげる
  vector<int> d;
  UnionFind(int n=0):d(n,-1){}
  int find(int x){
    // 根を返すfind関数
    // d[x] < 0 -> xは根
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x,int y){
    x = find(x); y = find(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x,int y){return find(x) == find(y);}
  int size(int x){return -d[find(x)];}
};

signed main(){
  int n,m;
  cin >> n >> m;
  vector<int> A(n);
  rep(i,0,n) cin >> A[i];
  UnionFind tree(n+1);
  rep(i,0,m){
    int x,y;
    cin >> x >> y;
    tree.unite(x,y);
  }
  int res = 0;
  rep(i,0,n){
    if(A[i] == i+1) res++;
    else{
      if(tree.same(A[i],i+1)) res++;
    } 
  }
  cout << res << endl;
}