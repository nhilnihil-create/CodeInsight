#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll imos[100005][35]={0};
int main(){
  ll n,c;
  cin>>n>>c;
  for(int i=1;i<=n;i++){
    ll s,t,u;
    cin>>s>>t>>u;
    imos[s-1][u]++;
    imos[t][u]--;
  }
  for(int i=0;i<100004;i++){
    for(int j=0;j<=c;j++) imos[i+1][j]+=imos[i][j];
  }
  ll ans=1;
  for(int i=0;i<100005;i++){
    ll kans=0;
    for(int j=0;j<=c;j++) kans+=(imos[i][j]>=1?1:0);
    ans=max(ans,kans);
  }
  cout<<ans<<endl;
}
