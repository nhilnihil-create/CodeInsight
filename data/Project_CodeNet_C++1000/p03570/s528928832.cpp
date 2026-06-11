#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
using namespace std;
// std::ios::sync_with_stdio(false);
typedef long long LL;
const int N = 250000;
const int M = 12;
const int INF = 0x3f3f3f3f;
const LL MOD = 1e9+7;
const double Pi = acos(-1);
int n,m;
char s[N];
int dp[1<<26];
int main()
{
    while (~scanf("%s",s))
    {
        memset(dp,INF,sizeof dp);
        int tmp = 0;
        dp[0] = 0;
        int l  = strlen(s);
        for (int i=0;i<l;i++)
        {
            tmp ^= 1<<(s[i]-'a');
            for (int j=0;j<26;j++)
                dp[tmp] = min(dp[tmp],dp[tmp^(1<<j)]+1);
        }
        printf("%d\n",max(1,dp[tmp]));
    }
    return 0;
}

/*

aabxyyzz
byebye
abcdefghijklmnopqrstuvwxyz
abcabcxabcx

*/