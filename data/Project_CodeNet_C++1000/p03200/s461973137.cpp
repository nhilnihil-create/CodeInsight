#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    Int ans = 0;
    Int w_pos = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            ans += (Int)(i-w_pos);
            w_pos++;
        }
    }
    cout << ans << endl;
}
