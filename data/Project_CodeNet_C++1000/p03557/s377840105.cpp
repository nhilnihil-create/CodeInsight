#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for ( int i = 0; i < N; i++ ) cin >> A.at(i);
    for ( int i = 0; i < N; i++ ) cin >> B.at(i);
    for ( int i = 0; i < N; i++ ) cin >> C.at(i);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long ans = 0;
    for ( int i = 0; i < N; i++ ) {
        int a = distance(A.begin(), lower_bound(A.begin(), A.end(), B.at(i)));
        int c = distance(upper_bound(C.begin(), C.end(), B.at(i)), C.end());
        ans += (long long)a * c;
    }

    cout << ans << endl;
    return 0;
}
