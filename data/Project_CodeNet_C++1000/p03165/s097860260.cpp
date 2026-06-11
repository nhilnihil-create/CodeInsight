#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3005
using namespace std;
int n,m,dp[M][M],fr[M][M];
char s[M],t[M];
int main()
{
    scanf("%s %s", s+1, t+1);
    n = strlen(s+1);
    m = strlen(t+1);

    REP(i,1,n) REP(j,1,m) {
        if (s[i] == t[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            fr[i][j] = 3;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            dp[i][j] = dp[i-1][j];
            fr[i][j] = 1;
        } else {
            dp[i][j] = dp[i][j-1];
            fr[i][j] = 2;
        }
    }

    string ans = "";
    int x=n, y=m;
    while (x && y) {
        if (fr[x][y] == 3) ans += s[x];

        int tmp = fr[x][y];
        if (tmp & 1) x--;
        if (tmp & 2) y--;
    }
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
    return 0;
}
