#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
string S, T;

int sn, tn;
vector<string> w;


void input() {
    cin >> S >> T;
}


void solve(int i) {
    string s = "";
    rep(j, i) {
        if (S[j] == '?') s += 'a';
        else s += S[j];
    }
    for (int j = i; j < i + tn; j++) {
        if (S[j] == '?') {
            s += T[j - i];
        } else if (S[j] == T[j - i]) {
            s += S[j];
        } else {
            return;
        }
    }
    for (int j = i + tn; j < sn; j++) {
        if (S[j] == '?') s += 'a';
        else s += S[j];
    }
    w.push_back(s);
}


int main() {
    input();
    sn = S.size();
    tn = T.size();
    if (sn < tn) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i, sn - tn + 1) solve(i);
    if (w.empty()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    sort(w.begin(), w.end());
    string ans = w[0];
    cout << ans << endl;
}
