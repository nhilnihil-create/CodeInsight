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
int arr[22][22];
int cache[1ll<<22];
int mod=1e9+7;
int dp(int bit)
{
    if(bit+1==(1ll<<n))
        return 1;
    int &ans=cache[bit];
    if(ans!=-1)
        return ans;
    ans=0;
    int row=__builtin_popcount(bit);
    for(int i=0;i<n;i++)
        if(arr[row][i] && !((1ll<<i)&bit))
            ans+=dp(bit|(1ll<<i));
    ans%=mod;
    return ans;
}
int32_t main() 
{
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    memset(cache,-1,sizeof(cache));
    print(dp(0));
}
