#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 9999;
    for (int i = 0; i < s.length()-2; i++) {
        int temp = 100*(s[i]-'0') + 10*(s[i+1]-'0') + (s[i+2]-'0');
        temp = abs(753-temp);
        ans = min(ans,temp);
    }

    cout << ans << endl;
}