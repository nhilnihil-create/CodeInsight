#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.size() < 26) {
        for (int i = 0; i < 26; i++) {
            if (find(all(s), 'a' + i) == s.end()) {
                s.push_back('a' + i);
                break;
            }
        }
    }
    else {
        for (int i = 25; i >= 0; i--) {
            char mn = 'z';
            bool ok = false;
            for (int j = i + 1; j < 26; j++) {
                if (s[i] < s[j]) {
                    ok = true;
                    mn = min(mn, s[j]);
                }
            }
            if (ok) {
                s.erase(s.begin() + i, s.end());
                s.push_back(mn);
                break;
            }
        }
        if (s.size() == 26)
            s = "-1";
    }

    cout << s << "\n";

    return 0;
}