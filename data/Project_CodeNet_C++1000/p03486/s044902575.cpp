#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

string Func(const string& str) {
    string s = str;
    sort(s.begin(), s.end());
    return s;
}
int main() {
    string s, t;
    cin >> s >> t;

    s = Func(s);
    t = Func(t);
    reverse(t.begin(), t.end());

#ifdef SOURCE_TEST
    cout << s << endl;
    cout << t << endl;

#endif

    bool isOk = true;
    for (ll i = 0; i <= s.size(); ++i) {
        if (i == s.size()) {
            if (t.size() <= i) {
                isOk = false;
            }
            break;
        }
        if (t.size() <= i) {
            isOk = false;
            break;
        }
        if (s[i] < t[i]) {
            break;
        } else if (s[i] > t[i]) {
            isOk = false;
            break;
        }
    }

    cout << (isOk ? "Yes" : "No") << endl;

    return 0;
}