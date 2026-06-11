#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define lfs <<fixed<<setprecision(10)<<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
using ll = long long;
using ld = long double;
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
template<typename T>
void debug(vector<vector<T>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
template<typename T>
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

ll MAX_V = 2e5 + 5;
vector<vector<ll>> G(MAX_V);//隣接リスト(添え字は始点、値は終点)

//引数は各頂点(0-indexed)の入次数
vector<ll>tsort(vector<ll>v){
  ll n=v.size();
  vector<ll>ret(n);
  stack<ll>st;
  for(ll i=0;i<n;i++)if(v[i]==0)st.push(i);
  for(ll i=0;i<n;i++){
    if(st.empty())return vector<ll>();//閉路がある
    ll x=st.top();
    st.pop();
    ret[x]=i;
    for(ll j=0;j<G[x].size();j++){
      v[G[x][j]]--;
      if(v[G[x][j]]==0)st.push(G[x][j]);
    }
  }
  return ret;
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  ll m=(1<<n);
  vector<ll>a(m);
  rep(i,0,m)cin>>a[i];
  ll maxbuf=0;
  vector<P>dp(m,MP(0,0));
  rep(i,0,m){
    dp[i].fi=i;
  }
  rep(i,0,m){
    bitset<18>x=i;
    rep(j,0,n){
      if(!x[j]){
        x[j]=1;
        set<P,greater<P>>tmp;
        ll k=x.to_ullong();
        tmp.emplace(a[dp[k].fi],dp[k].fi);
        tmp.emplace(a[dp[k].se],dp[k].se);
        tmp.emplace(a[dp[i].fi],dp[i].fi);
        tmp.emplace(a[dp[i].se],dp[i].se);
        dp[k]=MP(tmp.begin()->se,(++tmp.begin())->se);
        x[j]=0;
      }
    }
    //cout<<i spa dp[i].fi spa dp[i].se<<endl;
    if(i!=0)chmax(maxbuf,a[dp[i].fi]+a[dp[i].se]);
    if(i>=1)cout<<maxbuf<<endl;
  }
  return 0;
}