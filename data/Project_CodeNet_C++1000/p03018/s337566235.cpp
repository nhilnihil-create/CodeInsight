#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    string converted;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B' && s[i + 1] == 'C') {
            converted += 'D';
            i++;
        } else
            converted += s[i];
    }

    ll A = 0, ans = 0;
    for(int i = 0; i < converted.size(); i++) {
        if(converted[i] == 'A') {
            A++;
        } else if(converted[i] == 'D') {
            ans += A;
        } else
            A = 0;
    }

    cout << ans;
    return 0;
}
