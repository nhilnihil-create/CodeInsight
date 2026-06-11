#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
  int n;
  cin>>n;
  V<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i)a[i]+=a[i-1];
  }
  int l=0,r=2;
  ll ans=inf;
  for(int i=1;i<n-2;i++){
       ll bfol=abs(a[i]-a[l]-a[l]),bfor=abs(a[n-1]-a[r]-a[r]+a[i]);
       while(l+1<i&&abs(a[i]-a[l+1]-a[l+1])<bfol){
         l++;
         bfol=abs(a[i]-a[l]-a[l]);
       }
       while(r+1<n&&abs(a[n-1]-a[r+1]-a[r+1]+a[i])<bfor){
         r++;
         bfor=abs(a[n-1]-a[r]-a[r]+a[i]);
       }
       ll res=max({a[l],a[i]-a[l],a[r]-a[i],a[n-1]-a[r]})-min({a[l],a[i]-a[l],a[r]-a[i],a[n-1]-a[r]});
       chmin(ans,res);
  }
  cout<<ans<<"\n";
}
