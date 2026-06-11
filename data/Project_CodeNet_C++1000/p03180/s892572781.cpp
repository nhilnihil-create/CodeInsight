#include<bits/stdc++.h>
#define int long long
#define d lld
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int a[17][17] = {};
int dp[1<<16] = {};
int d[1<<16] = {};

void prepare(int N) {
    for (int i=0; i < 1<<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                if (i&(1<<j) && i&(1<<k)) {
                    d[i] += a[j][k];
                }
            }
        }
    }
}

main() {
    int i,j;
    int N;

    cin >> N;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    prepare(N);

    for (i=1; i < 1<<N; i++) {
        j = i;
        while(j) {
            dp[i] = max( dp[i], dp[i^j] + d[j]);
            j = (j-1) & i;
        }
        de(1) printf(">>> %lld\n", dp[i]);
    }

    printf("%lld\n", dp[(1<<N) - 1]);

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
