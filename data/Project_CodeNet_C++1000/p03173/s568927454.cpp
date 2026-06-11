#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[400],sum[400][400],dp[400][400];

ll solve(int i, int j){
    // base case
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ans=(1LL<<60),temp;
    for(int k=i;k<j;k++){
        temp=solve(i,k)+solve(k+1,j)+sum[i][j];
        ans=min(ans,temp);
    }
    //cout<<"fnas "<<fans<<'\n';
    //fans+=ans;
    return dp[i][j]=ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //sum+=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum[i][j]=a[j]+((j==i)?0:sum[i][j-1]);
        }
    }
    memset(dp,-1,sizeof(dp));
    ll sd=solve(0,n-1);
    cout<<sd<<'\n';
}