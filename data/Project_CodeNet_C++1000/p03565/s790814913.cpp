#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    string S;
    cin >> S;
    string T;
    cin >> T;

    int ri = -1;
    for (int i = 0; i < S.size(); i++) {
        if (i > S.size() - T.size()) break;

        bool ok = true;
        for (int j = 0; j < T.size(); j++) {
            if (S[i + j] != T[j] && S[i + j] != '?') {
                ok = false;
                break;
            }
        }

        if (ok) {
            ri = i;
        }
    }

    if (ri == -1) {
        cout << "UNRESTORABLE" << endl;
    } else {
        for (int i = ri; i < ri + T.size(); i++) {
            S[i] = T[i - ri];
        }
        rep(i, S.size()) {
            if (S[i] == '?') {
                S[i] = 'a';
            }
        }

        cout << S << endl;
    }
}