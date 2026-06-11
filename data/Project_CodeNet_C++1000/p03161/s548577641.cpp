#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn =1000100;
typedef pair<ll,ll>p1;
typedef pair<pair<ll,ll>,ll>p2;
map<pair<pair<ll,ll>,ll>,ll>m1;
map<pair<ll,ll>,ll>m2;
const int MOD = 1e9;
const int N=351;
const int inf = 0x3f3f3f3f;
typedef pair<char, int> PAIR;
map<string,int>mm;
ll a[maxn];
ll dp[maxn];
int main()
{
    ll n,k;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        dp[i] = inf;
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=i-1;j>=max(1ll,i-k);j--)
        {
            dp[i] = min(dp[j]+abs(a[j]-a[i]),dp[i]);
        }
    }
    cout<<dp[n]<<endl;
}