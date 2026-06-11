#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 2e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    string s;
    cin >> s;
    int len = s.size();
    if (len <= 4 || 10 <= len ){
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < (1 << (len + 1)); i++) {
        string ans;
        for (int j = 0; j < len + 1; j++) {
            if (i & (1 << j)) {
                ans += 'A';
            }
            if (j != len) ans += s[j];
        }
        if (ans == "AKIHABARA") {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
