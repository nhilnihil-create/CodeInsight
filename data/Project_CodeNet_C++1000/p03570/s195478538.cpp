#include<bits/stdc++.h>
using namespace std;

string S;
int N;
vector<int> pxor, dp;
int chk[1<<26];

int main() {
    cin >> S;
    N = S.size();

    pxor.resize(N);
    for(int i = N - 1; i >= 0; i--) {
        pxor[i] = (1<<(S[i] - 'a'));
        if(i != N - 1) pxor[i] ^= pxor[i + 1];
    }

    memset(chk, -1, sizeof(chk));
    dp = vector<int>(N + 1, 1e9);

    chk[0] = N;
    dp[N] = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(chk[ pxor[i] ] != -1) dp[i] = min(dp[i], (i == 0) + dp[ chk[ pxor[i] ] ]);
        for(int j = 0; j < 26; j++) {
            if(chk[ pxor[i] ^ (1<<j) ] != -1) dp[i] = min(dp[i], 1 + dp[ chk[ pxor[i] ^ (1<<j) ] ]);
        }
        chk[ pxor[i] ] = i;
    }

    printf("%d", dp[0]);
}
