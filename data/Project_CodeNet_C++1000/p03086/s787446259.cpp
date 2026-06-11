#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s.at(i);
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            cur++;
        }
        else {
            ans = max(ans, cur);
            cur = 0;
        }
    }
    ans = max(ans, cur);
    cout << ans << endl;
    return 0;
}