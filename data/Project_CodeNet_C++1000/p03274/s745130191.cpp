#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){

  int n,k;
  cin>>n>>k;
  vector<ll> x(n);
  rep(i,n)cin>>x[i];
  ll ans = 400000000;
  //rep(i,n)cout<<x[i];
  if(x[n-1]<=0){
    cout<<abs(x[n-k])<<endl;
    //cout<<x[n-k];
    return 0;
  }
  auto i0 = lower_bound(x.begin(),x.end(),0)-x.begin();
  if(i0==0){
    cout<<x[k-1]<<endl;
    //cout<<222;
    return 0;
  }
  for(int i=i0;i<n;i++){
    if(i>=k+i0-1)break;
    if(i-k+1>=0){
    //printf("l %d r %d\n",x[i-k+1],x[i]);
    ll mn=min(2*abs(x[i])+abs(x[i-k+1]),2*abs(x[i-k+1])+abs(x[i]));
    ans = min(ans,mn);
    //cout<<ans<<endl;
    }
  }
  if(i0-k>=0)ans = min(ans,abs(x[i0-k]));
  if(i0+k-1<n)ans = min(ans,x[i0+k-1]);
  cout<<ans;
  return 0;
}