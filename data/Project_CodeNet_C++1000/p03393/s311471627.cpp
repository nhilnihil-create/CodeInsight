#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    string ans;
    if (n < 26) {
        bool include[26];
        for (int i = 0; i < 26; i++) {
            include[i] = false;
        }
        for (int i = 0; i < n; i++) {
            include[(int)(s[i] - 'a')] = true;
        }
        ans = s;
        for (int i = 0; i < 26; i++) {
            if (!include[i]) {
                ans += (char)('a' + i);
                break;
            }
        }
    } else {
        bool flag = false;
        for (int i = n - 1; i > 0; i--) {
            if (s[i - 1] < s[i]) {
                flag = true;
                ans = s.substr(0, i - 1);
                for (int j = n - 1; j >= i; j--) {
                    if (s[j] > s[i - 1]) {
                        ans += s[j];
                        break;
                    }
                }
                break;
            }
        }
        if (!flag) ans = "-1";
    }

    cout << ans << endl;
    return 0;
}