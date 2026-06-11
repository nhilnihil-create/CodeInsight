#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    string s, rs;
    cin >> s;
    rs = s;
    reverse(rs.begin(), rs.end());
    if (rs[0] == '1' || s[0] == '0' || s.substr(0, s.size() - 1) != rs.substr(1, rs.size() - 1)) {
        cout << -1 << endl;
        return 0;
    }

    int head = 1;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '1') {
            cout << head << " " << i + 1 << endl;
            for (int j = head + 1; j <= i; j++) {
                cout << j << " " << i + 1 << endl;
            }
            head = i + 1;
        }
    }
    cout << head << " " << s.size() << endl;
    return 0;
}