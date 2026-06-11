#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> A(N), B(N);
    REP(i, 0, N) cin >> A[i];
    REP(i, 0, N) cin >> B[i];

    ll cnta = 0, cntb = 0;
    REP(i, 0, N) {
        if (A[i] > B[i]) {
            cntb += A[i] - B[i];
        } else if (A[i] < B[i]) {
            if ((B[i] - A[i]) % 2 == 0) {
                cnta += (B[i] - A[i]) / 2;
            } else {
                cnta += (B[i] - A[i]) / 2 + 1;
                cntb++;
            }
        }
    }
    // cout << cnta << " " << cntb << endl;
    if (cnta >= cntb) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}