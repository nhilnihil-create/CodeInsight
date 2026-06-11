#include <bits/stdc++.h>
using namespace std;


#define clr(arr,val) memset(arr,val ,sizeof arr)
typedef  long long ull;
typedef long long ll;


ll const oo=1e9 ;
int const SZ= (int)1e3+3;
const ll mod=(ll)1e9+7;

string str[SZ];
ll dp[SZ][SZ];
int r,c;
ll solve(int i ,int j){
    
    if(j<0 || j>=c)
        return 0;
    if(i<0 || i>=r)
        return 0;
    if(str[i][j]=='#')
        return 0;
    ll &ret=dp[i][j];
    if(~ret) return ret;
    if(i==r-1 && j==c-1)
        return 1;
    return ret=((solve(i+1,j)%mod)+(solve(i,j+1)%mod))%mod;
    
}
int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
        cin>>str[i]; 
    clr(dp,-1);
    cout<<solve(0,0)<<endl;
        
    return 0;
}