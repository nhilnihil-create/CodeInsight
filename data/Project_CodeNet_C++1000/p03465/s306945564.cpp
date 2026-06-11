#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
bool dp[2005][100005];
int main(){
  ll n,sum=0;
  cin>>n;
  for(ll i=0;i<2005;i++){
    for(ll j=0;j<100005;j++) dp[i][j]=false;
  }
  dp[0][0]=true;
  if(n==1){
    ll a;
    cin>>a;
    cout<<a<<endl;
    return 0;
  }
  else if(n<25){
    ll array[27];
    for(int i=0;i<n;i++) cin>>array[i];
    vector<ll> v;
    for(int b=0;b<(1<<n);b++){
      ll kans=0;
      for(int i=0;i<n;i++){
        if(((b>>i)&1)==1) kans+=array[i];
      }
      v.push_back(kans);
    }
    sort(v.begin(),v.end());
    int idx=1;
    for(int i=1;i<n;i++) idx*=2;
    cout<<v[idx]<<endl;
    return 0;
  }
  for(ll i=0;i<n;i++){
    ll a;
    cin>>a;
    sum+=a;
    for(ll j=0;j<100005;j++){
      if(dp[i][j]){
        if(j+a<100005) dp[i+1][j+a]=true;
        if(abs(j-a)<100005) dp[i+1][abs(j-a)]=true;
      }
    }
  }
  ll ans=1e15;
  for(ll i=0;i<100005;i++){
    if(dp[n][i]) ans=min(ans,i);
  }
  cout<<(sum+ans)/2<<endl;
}
