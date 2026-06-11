#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[200005];
const int mod=1e9+7;
int lol[200005];
int pos[200005];
int z[200005];

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
    int a[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int>temp;
    temp.push_back(0);
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            temp.push_back(a[i]);
        s.insert(a[i]);
    }
    map<int,int>mm;
    int cnt=0;
    for(auto i:s)
        mm[i]=++cnt;
    int sz=temp.size();
    for(int i=1;i<sz;i++)
    {
        temp[i]=mm[temp[i]];
        pos[i]=z[temp[i]];
        z[temp[i]]=i;
    }

    int ans=0;
    dp[0]=1;
    for(int i=1;i<sz;i++)
    {        
        if(pos[i]!=0)
            dp[i]=dp[pos[i]]+dp[i-1];
        else
            dp[i]=dp[i-1];
        dp[i]%=mod;
    }
    cout<<dp[sz-1];

} 
