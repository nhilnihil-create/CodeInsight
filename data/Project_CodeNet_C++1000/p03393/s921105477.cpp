#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

// 参考：https://iloveconviniboshi.hatenablog.com/entry/2019/11/19/013117
// 参考：https://par.hateblo.jp/entry/2018/04/01/205547

int main() {

    string s; cin >> s;

    if (s.length() != 26) {
        vector<int> c(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            c[s[i] - 'a'] = 1;
        }

        for (int i = 0; i < 26; ++i) {
            if (c[i] == 0) {
                cout << s << char(i + 'a') << endl;
                return 0;
            }
        }
    } else {
        // 26文字の場合
        string next = s;
        if (next_permutation(next.begin(), next.end())) {
            for (int i = 0; i < 26; ++i) {
                if (next[i] == s[i]) {
                    cout << next[i];
                } else {
                    cout << next[i];
                    break;
                }
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}