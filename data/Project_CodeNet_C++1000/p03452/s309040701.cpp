#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
void debug(vector<vector<ll>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
void debug(vector<ll>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
vector<vector<ll>>vec(ll x, ll y, ll w){
  vector<vector<ll>>v(x,vector<ll>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->se++;

struct UnionFind {
  vector<ll> data;
  vector<ll> difweight;
  UnionFind(ll size){
    data.assign(size,-1);
    difweight.assign(size,0);
  }
  bool unite(ll x, ll y, ll w) { //xがyの親に
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y), w = -w;
      data[x] += data[y]; 
      data[y] = x;
      difweight[y] = w;
    }
    return x != y;
  }
  bool find(ll x, ll y) {
    return root(x) == root(y);
  }
  ll diff(ll x,ll y){
    return weight(y)-weight(x);
  }
  ll weight(ll x){
    root(x);
    return difweight[x];
  }
  ll root(ll x) {
    if(data[x] < 0){
      return x;
    }
    else{
      ll tmp = root(data[x]);
      difweight[x] += difweight[data[x]];
      return data[x] = tmp;
    }
  }
  ll size(ll x) {
    return -data[root(x)];
  }
  ll debug(){
    rep(i,0,data.size()){
      root(i);
      cout<<i spa data[i] spa difweight[i] spa weight(i)<<endl;
    }
    cout<<endl;
  }
};

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<ll>l(m),r(m),d(m);
  UnionFind uf(n);
  rep(i,0,m)cin>>l[i]>>r[i]>>d[i];
  rep(i,0,m){
    l[i]--,r[i]--;
    if(uf.find(l[i],r[i])){
      if(uf.diff(l[i],r[i])!=d[i]){
        judge=false;
        break;
      }
    }
    else{
      uf.unite(l[i],r[i],d[i]);
    }
    //cout<<uf.diff(l[i],r[i])<<endl;
    //uf.debug();
  }
  ans1(judge);
  return 0;
}