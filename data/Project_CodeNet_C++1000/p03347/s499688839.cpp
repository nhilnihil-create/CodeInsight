#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i && A[i] == A[i - 1] + 1) {
            ans++;
            continue;
        }
        if (A[i] > i || (i && A[i] > A[i - 1] + 1)) {
            cout << -1 << endl;
            return 0;
        } else {
            ans += A[i];
        }
    }
    cout << ans << endl;

    return 0;
}