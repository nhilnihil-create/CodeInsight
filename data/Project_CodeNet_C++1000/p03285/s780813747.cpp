#include<bits/stdc++.h>
using namespace std;

#define int long long int 
int coe[2];
int dp[1000];

void find(int n)
{
    coe[0]=4;
    coe[1]=7;
    memset(dp,0,sizeof(dp));

    dp[0]=1;

    for(int i=0;i<2;i++)
        for(int j=coe[i];j<=n;j++)
                dp[j]+=dp[j-coe[i]];

}
int32_t main()
{
    int n;
    cin>>n;
    find(n);
     cout<<(dp[n]?"Yes":"No")<<endl;
}