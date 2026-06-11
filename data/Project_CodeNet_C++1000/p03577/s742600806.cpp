#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    string ans = "";
    for(int i = 0; i < n - 8; i++) {
        ans += s[i];
    }
    cout << ans << "\n";
    return 0;
}