#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n;
    cin>>n;
    int a[n+1];
    bitset<4000005>dp;
    int sum=0;
    for(int i=1;i<=n;i++)
    {        
        cin>>a[i];
        sum+=a[i];
    }

    if(n==1)
    {
        cout<<a[1];
        return 0;
    }
    dp.set(0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp|=(dp<<a[i]);
    }
    if(sum%2==0)
    {
        if(dp[sum/2])
        {
            cout<<sum/2;
            return 0;
        }
    }
    sum/=2;
    for(int i=sum+1;i<=4000000;i++)
    {
        if(dp[i])
        {
            cout<<i;
            return 0;
        }
    }
} 
