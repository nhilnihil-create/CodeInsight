#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    long long k;
    cin >> s >> k;
    int n = (int) s.size();
    vector<string> a(n);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] != '1') {
            pos = i;
            break;
        }
    }
    if(k >= pos + 1) {
        cout << s[pos];
    }
    else {
        cout << s[k - 1];
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
