#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

const int MX_N = 2e4+5;
const int MX_NA = 4e6+5;

int N, A[MX_N];
bitset<MX_NA> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int S = 0;
    FOR(i,1,N) { cin >> A[i]; S += A[i]; }

    S = (S+1)/2;
    dp.reset(); dp[0] = 1;
    FOR(i,1,N) {
        dp |= dp << A[i];
    }
    FOR(i,S,MX_NA-1) if (dp[i]) { cout << i; return 0; }
}
