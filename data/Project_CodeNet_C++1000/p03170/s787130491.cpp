#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int dp[100100];

int main()
{
    int n,m,p,q,i,j,k,l;
    cin>>n>>m;

    dp[0]=0;

    int ara[n+1];
    for(i=1;i<=n;i++) cin>>ara[i];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(i-ara[j]>=0) dp[i]=1-dp[i-ara[j]];
            if(dp[i]==1)break;
        }
    }

    if(dp[m]==1) cout<<"First\n";
    else cout<<"Second\n";
}
