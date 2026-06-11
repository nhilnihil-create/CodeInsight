#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int64_t ans = 0;
    for (int64_t i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            if (s[i] == 'x') {
                s.insert(s.end() - i, 'x');
                ans++;
            } else if (s[s.size() - 1 - i] == 'x') {
                s.insert(s.begin() + i, 'x');
                ans++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << ans << endl;
}