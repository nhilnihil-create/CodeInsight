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


int main()
{
    
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<bool>dp(k+1);
    for(int i=0;i<=k;i++)
    dp[i]=false;
    for(ll stones=0;stones<=k;stones++)
    {
        for(int x:a)
        {
            if(stones-x>=0&&!dp[stones-x])
            dp[stones]=true;
        }
    }

    if(dp[k])
    cout<<"First";
    else cout<<"Second";
}