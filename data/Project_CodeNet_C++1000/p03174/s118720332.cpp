#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
#define mod 1000000007;
int n;
long long int dp[22][N];
int arr[22][22];

long long int sol(int p, int msk){
      //cout<<p<<' ';
      if(p==n)return 1;
      if(dp[p][msk]!=-1)return dp[p][msk];
      long long int ans=0;
      for(int i=0; i<n; i++){
            if( (!(msk & (1<<(i)))) && arr[p][i]==1){
                  long long int m=(msk| (1<<i));
                  ans+=(sol(p+1, m));
                  ans%=mod;
            }
      }
      //cout<<p<<' '<<msk<<" "<<ans<<'\n';
      return dp[p][msk]=ans;
} 

int main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      cin>>n;
      int msk=0;
      for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                  cin>>arr[i][j];
            }
      memset(dp, -1, sizeof(dp));
      cout<<sol(0, 0)<<'\n';
}