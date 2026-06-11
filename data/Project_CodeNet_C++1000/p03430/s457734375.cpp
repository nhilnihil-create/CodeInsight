#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ind(a) scanf("%d", &a)
#define inlld(a) scanf("%lld", &a)
#define ind2(a, b) scanf("%d%d", &a, &b)
#define inlld2(a, b) scanf("%lld%lld", &a, &b)
#define ind3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define inlld3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

using namespace std;

const int N=305;
const int MOD=1e9+7;

typedef long long ll;
typedef long double ld;

string s;
int k, n, dp[N][N][N];

int solve(int i, int j, int left)
{
    if(left<0)
        return -1e9;
    if(i==j)
        return 1;
    if(i>j)
        return 0;
    if(dp[i][j][left]!=-1)
        return dp[i][j][left];
    int ret=0;
    if(s[i]==s[j])
        ret=solve(i+1, j-1, left)+2;
    else
        ret=solve(i+1, j-1, left-1)+2;
    ret=max(ret, solve(i+1, j, left));
    ret=max(ret, solve(i, j-1, left));
    // printf("%d %d %d %d\n", i, j, left, ret);
    return dp[i][j][left]=ret;
}

int main() 
{
    cin>>s>>k;
    n=s.length();
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0,n-1,k));
    return 0;
}

