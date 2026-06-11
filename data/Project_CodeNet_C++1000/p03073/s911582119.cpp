#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    
    s = " " + s;
    int n = s.size();
    int cnt = 0;
    rep(i, n) {
        if (i == 0 || i == 1) continue;
        if (s[1] == '1') {
            if (i % 2 == 0 && s[i] == '1') cnt++;
            if (i % 2 == 1 && s[i] == '0') cnt++;
        }
        if (s[1] == '0') {
            if (i % 2 == 0 && s[i] == '0') cnt++;
            if (i % 2 == 1 && s[i] == '1') cnt++;
        }
    }
    cout << cnt << endl;
}