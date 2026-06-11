//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
int arr[17][17];
int val[1ll<<17];
int cache[1ll<<17];
bool vis[1ll<<17];
int dp(int mask)
{
    if(!mask)
        return 0;
    if(vis[mask])
        return cache[mask];

    int maxans=val[mask];
    for(int submask = mask; submask; submask=(submask-1)&mask)
        if(submask!=mask)
            maxans=max(maxans,dp(submask)+dp(mask-submask));

    cache[mask]=maxans;
    vis[mask]=1;
    return maxans;
}
int32_t main() 
{
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    for(int i=0;i<(1ll<<n);i++)
    {
        int ans=0;
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(i&(1ll<<j))
                    if(i&(1ll<<k))
                        ans+=arr[j][k];
        val[i]=ans;
    }
    print(dp((1ll<<n)-1));
}
