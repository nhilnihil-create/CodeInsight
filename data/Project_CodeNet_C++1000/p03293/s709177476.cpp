#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string s, t, tmp;
    cin >> s >> t;
    bool ans = false;
    int len = s.size() - 1;
    rep(i, len + 1) {
        if (s == t) {
            ans = true;
            break;
        }
        s += s[0];
        s = s.substr(1, len+1);
    }

    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}