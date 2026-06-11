#include<bits/stdc++.h>
#define int long long
#define d lld
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define MOD 1000000007
#define de(x) if(x!=0 && MODE==x)
#define MODE 1

using namespace std;

int N;
char s[3007] = {};
int dp[3007][3007] = {};
int pre[3007][3007] = {};

int sum(int idx, int l, int r) {
    return ( ( pre[idx][r] - pre[idx][l-1] ) % MOD + MOD ) % MOD;
}

main() {
    int i,j;

    scanf("%d", &N);
    scanf("%s", s+1);
    dp[1][1] = 1;
    pre[1][1] = 1;
    for (i=2; i <= N; i++) {
        if (s[i-1] == '<') {
            for (j=2; j <= i; j++) {
                dp[i][j] += sum( i-1, 1, j-1);
                dp[i][j] %= MOD;
            }
        } else if (s[i-1] == '>') {
            for (j=1; j < i; j++) {
                dp[i][j] += sum( i-1, j, i-1);
                dp[i][j] %= MOD;
            }
        }

        for (j=1; j<=i; j++) {
            pre[i][j] = pre[i][j-1] + dp[i][j];
            pre[i][j] %= MOD;
        }
    }

    int ans = sum( N, 1, N);
    printf("%d\n", ans);

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
