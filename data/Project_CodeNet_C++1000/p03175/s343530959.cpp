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
vector<int>v[100005];
int dp[2][100005];
int mod=1e9+7;
int dfs(int pos,int par,int cl)
{
    if(v[pos].size()==1 && par!=0)
        return 1;
    int &ans=dp[cl][pos];
    if(ans!=-1)
        return ans;
    ans=1;
    for(int i:v[pos])
        if(i!=par)
        {
            if(cl==0)
                ans*=dfs(i,pos,0)+dfs(i,pos,1);
            else
                ans*=dfs(i,pos,0);
            ans%=mod;
        }
    dp[cl][pos]=ans%mod;
    return dp[cl][pos];
}
int32_t main() 
{
    IOS;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(n==1)
        return cout<<2,0;
    memset(dp,-1,sizeof(dp));
    print((dfs(1,0,0)+dfs(1,0,1))%mod);
}
