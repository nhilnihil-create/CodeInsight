#include <iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long int,long long int>,null_type,less<pair<long long int,long long int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void go()
{
    int n;
    cin>>n;
    vector<double> a(n);
    for(int i =0;i<n;i++)
        cin>>a[i];
    vector<vector<double> > dp(n+1,vector<double>(n+1,1));
//    for(int i=1;i<n;i++)
//        dp[0][i]=0;
//    dp[1][0]=1-a[0];
//    dp[1][1]=a[0];
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=dp[i-1][i-1]*a[i-1];
        for(int j=i-1;j>=0;j--)
            dp[i][j]=dp[i-1][j]*(1-a[i-1])+dp[i-1][j-1]*a[i-1];
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=0;j<n;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    double ans=0;
    for(int i=n/2+1;i<=n;i++)
        ans+=dp[n][i];
    //cout<<<<ans<<endl;
    printf("%.10f",ans);
}
int main()
{
    FIO;
//    int t;
//    cin>>t;
//    while(t--)
        go();
    return 0;
}
