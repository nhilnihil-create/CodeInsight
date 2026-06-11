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
    for (int i = 0; i < (1 << 4); i++) {
        string ans;
        if (i & (1 << 0)) ans += 'A';
        ans += "KIH";
        if (i & (1 << 1)) ans += 'A';
        ans += "B";
        if (i & (1 << 2)) ans += 'A';
        ans += "R";
        if (i & (1 << 3)) ans += 'A';
        if (ans == s) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
