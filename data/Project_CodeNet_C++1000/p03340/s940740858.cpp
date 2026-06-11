#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++)cin >> a[i];

  mat dp(21,vec(n+1));

  for(ll i=0;i<n;i++){
    for(ll j=0;j<20;j++){
      dp[j][i+1]=dp[j][i];
      if((1<<j) & a[i])dp[j][i+1]++;
    }
  }

  ll ans=0;
  for(ll i=0;i<n;i++){
    ll r=i+1,l=n+1;
    ll h;
    while(abs(r-l)>1){
      h=(r+l)/2;
      bool ok=1;
      for(ll j=0;j<20;j++){
        if(dp[j][h]-dp[j][i]>1){
          ok=0;
          break;
        }
      }
      if(ok){
        r=h;
      }
      else{
        l=h;
      }
    }
    ans+=(r-i);
    //cout << r << endl;
  }

  cout << ans << endl;
}