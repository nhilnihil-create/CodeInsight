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

    vector<int> a_sum(N+1);
    a_sum.at(0) = a.at(0);
    for ( int i = 1; i <= N; i++ ) {
        a_sum.at(i) = a_sum.at(i-1) + a.at(i);
    }

    int ans = min(a_sum.at(X), a_sum.at(N) - a_sum.at(X));

    cout << ans << endl;
    return 0;
}
