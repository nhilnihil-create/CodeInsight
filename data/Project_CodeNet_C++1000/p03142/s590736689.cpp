#include <bits/stdc++.h> // ver2.3.6
#include <boost/math/tools/minima.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define fmin brent_find_minima
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,k) upper_bound(ALL(a),k)-lower_bound(ALL(a),k)
#define BIGGER(a,k) a.end()-upper_bound(ALL(a),k)
#define SMALLER(a,k) lower_bound(ALL(a),k)-a.begin()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define VTiii vector<Tiii>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define PI 3.141592653589793238462
#define MOD 1000000007  //  10^9 + 7

using namespace std;
/* fmin(f,L,R,100) で関数の最小値を(x,min)で返す　*/
using boost::math::tools::brent_find_minima;
/* cpp_int (任意の長さのint) */
using boost::multiprecision::cpp_int;

/* デバッグ用 */
void Vout(auto a){if(a.size()==0) cout<<"."<<endl;
else{rep(i,0,a.size()-1)cout<<a[i]<<' ';if(a.size()>0)cout<<a.back()<<endl;}return;}
void Verr(auto a){if(a.size()==0) cerr<<"."<<endl;
else{rep(i,0,a.size()-1)cerr<<a[i]<<' ';if(a.size()>0)cerr<<a.back()<<endl;}return;}
void VVout(auto a){if(a.size()==0)cout<<"."<<endl;
else{rep(i,0,a.size())Vout(a[i]);}return;}
void VVerr(auto a){if(a.size()==0)cerr<<"."<<endl;
else{rep(i,0,a.size())Verr(a[i]);}return;}
void VPout(auto a){if(a.size()==0)cout<<"."<<endl;
else{rep(i,0,a.size())cout<<a[i].FI<<' '<<a[i].SE<<endl;}return;}
void VPerr(auto a){if(a.size()==0)cerr<<"."<<endl;
else{rep(i,0,a.size())cerr<<a[i].FI<<' '<<a[i].SE<<endl;}return;}

/* 便利関数 */
int gcd(int a,int b){return b?gcd(b,a%b):a;} // 最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;} // 最小公倍数lcm
int mypow(int x, int n, int m){ // 累乗x^n(mod m) O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int scomb(int n, int r){if((n-r)<r)r=n-r; // nCr(小さい場合)
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
int comb(int n, int r){if((n-r)<r)r=n-r; // nCr(%MOD)
int a=1;for(int i=n;i>n-r;--i){a=a*i%MOD;}for(int i=1;
i<r+1;++i){a=a*mypow(i,MOD-2,MOD)%MOD;}return a%MOD;}
Vi stpowV(){Vi a(100001);
a[0]=1;repeq(i,1,100000)a[i]=a[i-1]*i%MOD;return a;}
//Vi stpow = stpowV();  // 階乗配列(%MOD)
void press(auto &v){v.erase(unique(ALL(v)),v.end());} // 圧縮
Vi Vsum(Vi &v){Vi S(v.size()+1);rep(i,1,S.size())S[i]+=v[i-1]+S[i-1];return S;} // 累積和
int keta(int k,int i){string s = itos(k);return s[s.size()-i]-'0';} // i桁目の数字


int v, e; // 頂点数、辺数
const int MAX_N = 100010; // 頂点数の最大値
vector<int> g[MAX_N]; // 隣接リスト
bool used[MAX_N];
vector<int> tpv; // トポロジカルソートされた数列

void dfs(int u) {
  if(used[u]) return;
  used[u] = true;
  for(auto& i: g[u]) dfs(i);
  // 帰りがけ順で追加
  tpv.push_back(u);
}

void tsort() {
  for(int i=0; i<v; ++i) dfs(i);
  reverse(tpv.begin(), tpv.end());
}



signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  
  int m;
  cin >> v >> m; // 頂点数v、辺数e
  e = v+m-1;
  //cerr<<e<<endl;
  
  VPii into(0);
  
  rep(i,0,e) {
    int s, t;
    cin >> s >> t; // s→tの有向辺
    s--,t--;  // 1-indexの場合
    g[s].push_back(t);
    
    into.pb(mp(s,t));
  }
  
  tsort();
  
  //Vout(tpv);
  
  int n = v;
  reverse(ALL(tpv));
  
  Vi ans(n);
  map<int,Pii> from;
  Vi va(n);
  rep(i,0,n){
    va[tpv[i]] = n-i;
  }
  
  //Vout(va);
  
  rep(i,0,n){
    from[i] = mp(-1,-1);
  }
  
  rep(i,0,into.size()){
    int s,t;
    s = into[i].FI;
    t = into[i].SE;
    
    Pii now = from[t];
    Pii next = mp(va[s],s);
    
    if(now < next) from[t] = next;
    
  }
  
  rep(i,0,n){
    cout << from[i].SE+1 << endl;
  }
  
  
  return 0;
}