#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vi A(N); rep(i, N) cin >> A[i];

    bool allplus = true;
    bool allminus = true;
    bool isok = true;
    rep(i, N) {
        if (A[i] < 0) allplus = false;
        if (A[i] > 0) allminus = false;

        if ((i != N - 1) && (A[i] > A[i + 1])) {
            isok = false;
        }
    }
    if (isok) {
        cout << 0 << endl;
        return 0;
    }

    if (allplus) {
        cout << (N - 1) << endl;
        for (int i = 1; i < N; i++) {
            cout << (i) << " " << (i + 1) << endl;
        }
    } else if (allminus) {
        cout << (N - 1) << endl;
        for (int i = N - 2; i >= 0; i--) {
            cout << (i + 2) << " " << (i + 1) << endl;
        }
    } else {
        int amax = -INF;
        int amaxi;
        int amin = INF;
        int amini;
        rep(i, N) {
            if (A[i] > amax) {
                amax = A[i];
                amaxi = i;
            }

            if (A[i] < amin) {
                amin = A[i];
                amini = i;
            }
        }

        cout << (2 * N - 2) << endl;
        if (abs(amax) >= abs(amin)) {
            rep(i, N) {
                if (i != amaxi) {
                    cout << (amaxi + 1) << " " << (i + 1) << endl;
                }
            }
            for (int i = 1; i < N; i++) {
                cout << (i) << " " << (i + 1) << endl;
            }
        } else {
            rep(i, N) {
                if (i != amini) {
                    cout << (amini + 1) << " " << (i + 1) << endl;
                }
            }
            for (int i = N - 2; i >= 0; i--) {
                cout << (i + 2) << " " << (i + 1) << endl;
            }
        }

    }
}