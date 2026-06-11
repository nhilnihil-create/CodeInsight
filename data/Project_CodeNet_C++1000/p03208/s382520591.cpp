#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N, K; scanf("%d%d", &N, &K);
    int A[100000]; rep(i, N) scanf("%d", &A[i]);
    sort(A, A + N);
    int ans = 1000000000;
    rep(i, N - K + 1) ans = min(ans, A[i + K - 1] - A[i]);
    cout << ans << endl;
    return 0;
}