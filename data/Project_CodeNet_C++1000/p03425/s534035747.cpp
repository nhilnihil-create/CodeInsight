#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    string s = "MARCH";
    vector<int> c(5);
    rep(i, n) {
        string t;
        cin >> t;
        for (int i = 0; i < (int)s.size(); i++) {
            if (t[0] == s[i]) {
                c[i]++;
                break;
            }
        }
    }
    Int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j=i+1; j < 5; j++) {
            for (int k= j+1; k < 5; k++) {
                ans += Int(Int(c[i]) * c[j] * c[k]);
            }
        }
    }
    cout << ans << endl;
}