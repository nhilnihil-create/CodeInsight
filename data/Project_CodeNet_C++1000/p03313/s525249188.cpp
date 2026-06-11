#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp1[20][(1<<18)+5]={0},dp2[20][(1<<18)+5]={0};
int main(){
  ll n;
  cin>>n;
  for(int i=0;i<(1<<n);i++) cin>>dp1[0][i];
  for(int t=0;t<n;t++){
    for(int m=0;m<(1<<n);m++){
      if(((m>>t)&1)==0){
        dp1[t+1][m]=dp1[t][m];
        dp2[t+1][m]=dp2[t][m];
      }
      else{
        ll m_=m&(~(1<<t));
        priority_queue<ll> pque;
        pque.push(dp1[t][m]);
        pque.push(dp2[t][m]);
        pque.push(dp1[t][m_]);
        pque.push(dp2[t][m_]);
        dp1[t+1][m]=pque.top();
        pque.pop();
        dp2[t+1][m]=pque.top();
        pque.pop();
      }
    }
  }
  ll ans=dp1[n][0]+dp2[n][0];
  for(int i=1;i<(1<<n);i++){
    ans=max(ans,dp1[n][i]+dp2[n][i]);
    cout<<ans<<endl;
  }
}
