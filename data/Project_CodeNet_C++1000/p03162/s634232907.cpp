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
ll a[maxn],b[maxn],c[maxn];
ll dp[maxn][4];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d%d%d",&a[i],&b[i],&c[i]);
    dp[1][1] = a[1];dp[1][2] = b[1];dp[1][3] = c[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][1] = max(dp[i-1][2]+a[i],dp[i-1][3]+a[i]);
        dp[i][2] = max(dp[i-1][1]+b[i],dp[i-1][3]+b[i]);
        dp[i][3] = max(dp[i-1][2]+c[i],dp[i-1][1]+c[i]);
    }
    printf("%lld",max(dp[n][1],max(dp[n][2],dp[n][3])));
}