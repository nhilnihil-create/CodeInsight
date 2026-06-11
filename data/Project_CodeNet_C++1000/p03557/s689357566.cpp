#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        auto j = lower_bound(A.begin(), A.end(), B[i]);
        auto k = upper_bound(C.begin(), C.end(), B[i]);
        long long cnt = distance(A.begin(), j);
        cnt *= distance(k, C.end());
        ans += cnt;
    }

    cout << ans << endl;
}