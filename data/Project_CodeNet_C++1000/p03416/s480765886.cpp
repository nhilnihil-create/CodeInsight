#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (rs == s) ans++;
    }
    cout << ans << endl;
    return 0;
}