#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    string s, t = "";
    cin >> s;
    int n = s.size();
    rep(i, n) {
        if (i < n - 1 && s[i] == 'B' && s[i + 1] == 'C') {
            t.push_back('D');
            i++;
        } else {
            t.push_back(s[i]);
        }
    }
    //cout << t << "\n";
    ll ans = 0, A = 0;
    n = t.size();
    rep(i, n) {
        if (t[i] == 'A') A++;
        else if (t[i] == 'D') ans += A;
        else A = 0;
    }
    cout << ans << "\n";
}