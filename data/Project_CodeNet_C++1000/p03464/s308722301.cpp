#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int K; cin >> K;
    vector<ll> A(K);
    REP(i, 0, K) cin >> A[i];

    if (A.back() > 2) {
        cout << -1 << endl;
        return 0;
    }

    ll l = 2, h = 2;
    for (int i = K - 1; i > 0; i--) {
        if (l < A[i] || h < A[i]) {
            cout << -1 << endl;
            return 0;
        }
        // cout << "# i : " << i << " : " << A[i] << endl;
        l = l / A[i] * A[i];
        h = (h / A[i] + 1) * A[i] - 1;
        // cout << "--> " << l << " " << h << endl;

        ll nl = (l + A[i - 1] - 1) / A[i - 1] * A[i - 1];
        ll nh = h / A[i - 1] * A[i - 1];
        nl = min(nl, nh);
        if (nl == 0 && nh != 0) nl += A[i - 1];

        if (nl > h || nh < l) {
            cout << -1 << endl;
            return 0;
        }
        h = nh; l = nl;

        // cout << "--> " << l << " " << h << endl;
    }
    h = (h / A[0] + 1) * A[0] - 1;
    cout << l << " " << h << endl;
    return 0;
}