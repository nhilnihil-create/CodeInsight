#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;

    int alphabets[26] = {};
    REP(i, 0, s.size()) alphabets[s[i] - 'a']++;

    REP(i, 0, 26) {
        if (alphabets[i] == 0) {
            cout << s << (char)('a' + i) << endl;
            return 0;
        }
    }

    string t = s;
    next_permutation(t.begin(), t.end());
    if (t < s) {
        cout << -1 << endl;
        return 0;
    }

    string ans = "";
    REP(i, 0, 26) {
        ans += t[i];
        if (s[i] != t[i]) break;
    }
    cout << ans << endl;
    return 0;
}