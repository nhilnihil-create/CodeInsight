#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    for ( int i = 0; i < M; i++ ) {
        cin >> A.at(i);
    }

    vector<int> a(N+1, 0);
    for ( int i = 0; i < M; i++ ) {
        a.at(A.at(i)) = 1;
    }

    int ans1 = 0;
    for ( int i = X; i <= N; i++ ) {
        ans1 += a.at(i);
    }
    int ans2 = 0;
    for ( int i = X; i >= 0; i-- ) {
        ans2 += a.at(i);
    }
    int ans = min(ans1, ans2);

    cout << ans << endl;
    return 0;
}
