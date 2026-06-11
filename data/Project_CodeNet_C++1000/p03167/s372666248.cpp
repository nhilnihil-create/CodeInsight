#include <bits/stdc++.h>
using namespace std;
#include <string.h>
#include <map>
#define MEM(var, val) memset(var, (val), sizeof(var))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define nitro                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
//*max_element(a.begin(), a.end())
vector<string>mat;
vector<vll>dp;
ll h,w;
ll paths(ll i,ll j)
{
    if(i>h-1||j>w-1)
    return 0;
    if(i==h-1&&j==w-1)
    return 1;
    if(mat[i][j]=='#')
    return 0;
    ll &ans=dp[i][j];
    if(ans!=-1)
    return ans;
    ans=paths(i+1,j)+paths(i,j+1);
    ans=ans%mod;
    return ans;
}
int main()
{
    
    cin>>h>>w;
    mat.clear();
    mat.resize(h);
    dp.clear();
    dp.resize(h);
    for(int i=0;i<h;i++)
    cin>>mat[i];
    for(int i=0;i<h;i++)
    dp[i].resize(w,-1);
    cout<<paths(0,0);

}