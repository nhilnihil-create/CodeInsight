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
const int maxn =1200100;
typedef pair<ll,ll>p1;
typedef pair<pair<ll,ll>,ll>p2;
map<pair<pair<ll,ll>,ll>,ll>m1;
map<pair<ll,ll>,ll>m2;
const int MOD = 1e9;
const int N=351;
const int inf = 1000010;
typedef pair<char, int> PAIR;
map<string,int>mm;
ll a[maxn];
ll dp[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n]<<endl;
}