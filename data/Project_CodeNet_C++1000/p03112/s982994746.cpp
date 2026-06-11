#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x, ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}
vector<vector<ll>>G(MAX);
vector<bool>seen(MAX,false);
vector<ll> ans(MAX);

void dfs(int p,int v){
  seen[v]=true;
  if(v!=0)ans[v]+=ans[p];
  for(auto nv:G[v]){
    if(!seen[nv]) dfs(v,nv);
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int a,b,q;
  cin >> a >> b >> q;
  vector<ll>s(a+2);
  vector<ll>t(b+2);
  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];
  s[a]=INF,s[a+1]=-INF;
  t[b]=INF,t[b+1]=-INF;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  rep(i,q){
    ll x;
    cin >> x;
    ll ans=INF;
    ll rs=abs(*lower_bound(s.begin(),s.end(),x));
    ll rt=abs(*lower_bound(t.begin(),t.end(),x));
    ll ls=abs(*(upper_bound(s.begin(),s.end(),x)-1));
    ll lt=abs(*(upper_bound(t.begin(),t.end(),x)-1));
    
    chmin(ans,abs(rs-x)+abs(rt-rs));
    chmin(ans,abs(rs-x)+abs(lt-rs));
    chmin(ans,abs(ls-x)+abs(rt-ls));
    chmin(ans,abs(ls-x)+abs(lt-ls));
    chmin(ans,abs(rt-x)+abs(rs-rt));
    chmin(ans,abs(rt-x)+abs(ls-rt));
    chmin(ans,abs(lt-x)+abs(rs-lt));
    chmin(ans,abs(lt-x)+abs(ls-lt));
    cout << ans << endl;
  }
    
  
}
