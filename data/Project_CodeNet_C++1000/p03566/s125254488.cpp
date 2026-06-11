#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

double dp[44444][222];

int main(){
  ll n,t[111],v[111];
  cin>>n;
  ll sum_t=0;
  for(int i=0;i<n;i++){
    cin>>t[i];
    t[i]*=2;
    sum_t+=t[i];
  }
  for(int i=0;i<n;i++){
    cin>>v[i];
    v[i]*=2;
  }
  fill_n(*dp,44444*111,-1);
  dp[0][0]=0;
  
  ll tv[44444];
  ll cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<t[i];j++){
	 if(j==0&&i)tv[cnt++]=min(v[i-1],v[i]);
	 else tv[cnt++]=v[i];
    }
  }

  for(int i=0;i<sum_t;i++){
    for(int j=0;j<=tv[i];j++){
	 if(dp[i][j]<0)continue;
	 dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(double)j/2.0);
	 dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+((double)j+0.5)/2.0);
	 if(j)dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+((double)j-0.5)/2.0);
	 
    }
  }
  printf("%.10lf\n",dp[sum_t][0]/2.0);
  /*
  for(int i=0;i<=sum_t;i++){
    for(int j=0;j<=40;j++){
	 cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  return 0;
}
