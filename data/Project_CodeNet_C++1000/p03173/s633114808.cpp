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
int arr[404];
int sum[404];
int cache[404][404];
int dp(int l,int r)
{
    if(r==l)
        return 0;
    int &ans=cache[l][r];
    if(ans!=-1)
        return ans;
    ans=1e18;
    for(int i=l;i<=r-1;i++)
        ans=min(ans,dp(l,i)+dp(i+1,r));
    ans+=sum[r]-sum[l-1];
    return ans;
}
int32_t main() 
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    memset(cache,-1,sizeof(cache));
    cout<<dp(1,n);
}
