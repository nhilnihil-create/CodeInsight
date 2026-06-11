#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define REPS(i,n) for(int i=1;i<=(int)(n);i++)
using namespace std;
using ll = long long;
using ld = long double;

int main(void) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int A[N];
    REP (i, N) {
        A[i] = S.at(i) - '0';
    }

    int block[N] = {};
    for (int i = 1; i < N; i++) {
        if (A[i] == A[i-1]) {
            block[i] = block[i-1];
        } else {
            block[i] = block[i-1] + 1;
        }
    }

    int ans = 0, sentinel;
    REP (i, N) {
        if (A[i] == 0) {
            sentinel = lower_bound(block, block+N, block[i]+K*2) - block;
        } else {
            sentinel = lower_bound(block, block+N, block[i]+K*2+1) - block;
        }
        ans = max(ans, sentinel - i);
    } 

    cout << ans << endl;
}