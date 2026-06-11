//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,k;
int arr[102];
int dp[2][100005];
int presum[100005];
int mod=1e9+7;
int32_t main() 
{
    IOS;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    dp[n%2][0]=1;
    for(int pos=n-1;pos>=0;pos--)
    {
        for(int i=1;i<=k+1;i++)
            presum[i]=presum[i-1]+dp[(pos+1)%2][i-1];
        for(int left=0;left<=k;left++)
        {
            int ans=0;
            //sum from max(0,left-arr[pos]) to left
            // for(int i=0;i<=min(left,arr[pos]);i++)
            //     ans+=dp[(pos+1)%2][left-i];
            ans=presum[left+1]-presum[max(0ll,left-arr[pos])];
            dp[pos%2][left]=ans%mod;
        }
    }
    print(dp[0][k]);
}
