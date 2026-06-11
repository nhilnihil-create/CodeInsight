#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int N; cin >> N;
    vector<int> A(N); for (auto& x : A) cin >> x;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if ((A[i] > i) || (i != 0 && A[i] - A[i-1] >= 2)) {
            cout << -1 << endl;
            return 0;
        }
        if (A[i] == 0) continue;
        ans += (A[i] == A[i-1] + 1) ? 1 : A[i];
    }
    cout << ans << endl;
}