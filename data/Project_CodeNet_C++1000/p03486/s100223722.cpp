#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    string S, T;
    cin >> S >> T;

    vi cs(S.size());
    vi ct(T.size());
    rep(i, S.size()) {
        cs[i] = S[i] - 'a';
    }
    rep(i, T.size()) {
        ct[i] = T[i] - 'a';
    }

    sort(cs.begin(), cs.end());
    sort(ct.begin(), ct.end());
    reverse(ct.begin(), ct.end());

    bool ok;
    if (S.size() < T.size()) {
        ok = true;
        for (int i = 0; i < S.size(); i++) {
            if (cs[i] < ct[i]) {
                ok = true;
                break;
            } else if (cs[i] > ct[i]) {
                ok = false;
                break;
            }
        }
    } else {
        ok = false;
        for (int i = 0; i < T.size(); i++) {
            if (cs[i] < ct[i]) {
                ok = true;
                break;
            } else if (cs[i] > ct[i]) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}