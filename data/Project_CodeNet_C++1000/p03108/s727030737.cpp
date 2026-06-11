#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define CHI 1000000000000000003
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

//-------------------------------------------------
// 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}

struct UnionFind {
  vint par ;  //iの親
  vint rank ; //木の深さ
  vll siz ; //iの属する集合の要素数
  
  //n要素の初期化
  void init(int n){
    REP(i,n){
      par.PB(i) ;
      rank.PB(0) ;
      siz.PB(1) ;
    }
  }
  
  //木の根を求める
  //根が一緒なら同じ集合と判断するため
  int find(int x){
    if(par[x]==x){
      return x ;
    }
    else{
      return par[x] = find(par[x]) ;
    }
  }
  
  //木の併合
  //記録してあるrankをもとに併合
  void unite(int x,int y){
    x = find(x) ;
    y = find(y) ;
    if(x==y){
      return ;
    }
    
    if(rank[x] < rank[y]){
      par[x] = y ;
      siz[y] += siz[x] ;
    }
    else{
      par[y] = x ;
      siz[x] += siz[y] ;
      if(rank[x]==rank[y]){
        rank[x]++ ;
      }
    }
  }
  
  //xとyが同じ集合に属するか
  bool same(int x,int y){
    return find(x) == find(y) ;
  }
  
  //iが根であるかを返す
  bool root(int x){
    return x==find(x) ;
  }
    
  
  //xの属する集合の要素数を返す
  ll size(int x){
    return siz[find(x)] ;
  }
  
  //グラフ全体で何個の集合があるか返す
  ll cnt(int n){
    ll res = 0 ;
    REP(i,n){
      if(i==find(i)){
        res++ ;
      }
    }
    return res ;
  }
  
};


//-------------------------------------------------
// メモ
/*






*/
//-------------------------------------------------


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m ;
  cin >> n >> m ;
  vll ans(m,0) ;
  
  UnionFind tree ;
  tree.init(n) ;
  
  UnionFind memo ;
  memo.init(n) ;
  
  vpii pai(m) ;
  
  REP(i,m){
    int a, b ;
    cin >> a >> b ;
    pai[i] = MP(a-1,b-1) ;
    memo.unite(a-1,b-1) ;
  }
  
  reverse(ALL(pai)) ;
  
  
  ans[0] = 0 ;
  
  REP(i,n){
    if(memo.root(i)){
      ans[0] += memo.size(i)*(memo.size(i)-1)/2 ;
    }
  }
  
  REP(i,m-1){
    int A, B ;
    A = pai[i].FI ;
    B = pai[i].SE ;
    if(!tree.same(A,B)){
      ans[i+1] = ans[i] - (tree.size(A)*tree.size(B)) ;
    }
    else{
      ans[i+1] = ans[i] ;
    }
    tree.unite(A,B) ;
  }
  
  REP(i,m){
    cout << ans[m-i-1] <<endl ;
  }

  return 0 ;
}

