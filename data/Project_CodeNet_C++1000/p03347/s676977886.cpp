#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

/*
    1 2 3 2 2 3
*/

int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];

    if (A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    REP(i, 1, N) {
        if (A[i - 1] + 1 < A[i]) {
            cout << -1 << endl;
            return 0;
        }
        if (A[i - 1] + 1 == A[i]) {
            ans++;
        } else {
            ans += A[i];
        }
    }

    cout << ans << endl;

    return 0;
}