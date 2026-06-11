#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,k,h[M],dp[M];
int main()
{
    scanf("%d %d", &n, &k);
    REP(i,1,n) scanf("%d", &h[i]);
    
    dp[1] = 0;
    REP(i,2,n) {
        dp[i] = 2000000000;
        for (int j=i-1; j>=max(1, i-k); j--) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}

