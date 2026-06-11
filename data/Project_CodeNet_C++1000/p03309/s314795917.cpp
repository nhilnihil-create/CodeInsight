#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for ( int i = 0; i < N; i++ ) cin >> A.at(i);

    for ( int i = 0; i < N; i++ ) A.at(i) -= i + 1;

    sort(A.begin(), A.end());

    int b = A.at(N/2);
    long long ans = 0;
    for ( int i = 0; i < N; i++ ) ans += abs(A.at(i) - b);

    cout << ans << endl;
    return 0;
}
