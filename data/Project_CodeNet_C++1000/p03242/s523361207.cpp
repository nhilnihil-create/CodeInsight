/**
 *    author:  tootal    
 *    created: 2020/04/11 15:49:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '1' && s[i] <= '9') {
            s[i] = '9' - s[i] + '1';
        }
    }
    cout << s << endl;
    return 0;
}