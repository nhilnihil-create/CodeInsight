#include <bits/stdc++.h>

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

using namespace std;

const int N = 3e3 + 3, MOD = 1e9 + 7;
int n, dp[N][N];
char s[N];

/**
int mem[N][N];
int solve(int i, int up){
    if(i == n) return mem[i][up] = 1;

    int& ret = mem[i][up];
    if(~ret) return ret;

    ret = 0;
    int down = n - (i + up);
    if(s[i] == '<' && up) for(int l = 1; l <= up; ++l){
        ret += solve(i + 1, up - l);
        if(ret >= MOD) ret -= MOD;
    }
    else if(s[i] == '>' && down) for(int l = 0; l < down; ++l){
        ret += solve(i + 1, up + l);
        if(ret >= MOD) ret -= MOD;
    }
    return ret;
}
**/

int main()
{
    s[0] = '<';
    scanf("%d %s", &n, s + 1);
    dp[n][0] = 1;
    for(int i = n - 1; ~i; --i){
        for(int up = 0; up <= n; ++up){
            int down = n - (up + i);
            if(down < 0) continue;
            if(s[i] == '<' && up){
                dp[i][up] = dp[i + 1][up - 1];
            }
            else if(s[i] == '>' && down){
                dp[i][up] = dp[i + 1][up + down - 1] - (up? dp[i + 1][up - 1] : 0) + MOD;
                if(dp[i][up] >= MOD) dp[i][up] -= MOD;
            }
            if(up){
                dp[i][up] += dp[i][up - 1];
                if(dp[i][up] >= MOD) dp[i][up] -= MOD;
            }
        }
    }
    int ans = dp[0][n] - dp[0][n - 1] + MOD;
    if(ans >= MOD) ans -= MOD;
    printf("%d\n", ans);


//    memset(mem, -1, (n + 3) * sizeof mem[0]);
//    printf("%d\n", solve(0, n));
    return 0;
}
