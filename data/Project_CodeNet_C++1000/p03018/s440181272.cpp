#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s; cin >> s;
    vector<int> c(s.length(), 0);
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == 'A') {
            c[i] = 1;
        } else if (s[i] == 'B' && s[i+1] == 'C') {
            c[i] = 2;
            i++;
        } else {
            c[i] = -1;
        }
    }
    int n = 0;
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (c[i] == 1) {
            n++;
        } else if (c[i] == 2) {
            ans += n;
        } else if (c[i] == -1) {
            n = 0;
        }
    }
    cout << ans << endl;
}
