#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    int k = s.size() - 1;
    int ans = k * 9;

    bool is_all_9 = true;
    for (int i = 1; i < s.size(); i++) {
        int a = s[i]-'0';
        if (a != 9) {
            is_all_9 = false;
            break;
        }
    }
    if (is_all_9) cout << ans+(int)(s[0] - '0') << endl;
    else cout << ans+ (int)(s[0]-'0' -1) << endl;
}