#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double>
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 1000000007


using namespace std;
int n;
int arr[22][22];
int dp[22][(1<<21)];
bool used[22];

/*

 ll solve(int index,int woman)
{
    if(index==n)
        return 1;


    if (~dp[index][woman])
        return dp[index][woman];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[index][i] && !used[i])
        {   used[i]=1;
            ans+=solve(index+1,i);
            ans%=mod;
            used[i]=0;
        }
    }
    return dp[index][woman]=ans;
}

 */

ll solve(int man,int woman)
{
    if(man==n)
        return 1;
    if (~dp[man][woman])
        return dp[man][woman];
    ll ans=0;
    for(int i=0;i<n;i++)
    {

        if(arr[man][i] && !((1<<i)& woman))
        {
            ans+=solve(man+1,(1<<i)| woman);
            ans%=mod;
        }
    }
    return dp[man][woman]=ans;
}
int main() {

    HS;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
        memset(dp,-1,sizeof(dp));
        cout << solve(0,0);
    return 0;
}