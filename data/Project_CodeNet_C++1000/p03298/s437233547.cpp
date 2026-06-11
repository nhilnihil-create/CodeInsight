#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string order(const string &s, int c) {
    int n = s.size();
    string ret;
    for (int i = 0; i < n; i++) {
        if (((c >> i) & 1) == 1) {
            ret.push_back(s[i]);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (((c >> i) & 1) == 0) {
            ret.push_back(s[i]);
        }
    }
    return ret;
}
    
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<unordered_map<string, int>> m(n+1);
    
    string fh = s.substr(0, n);
    for (int i = 0; i < (1 << n); i++) {
        int c = __builtin_popcount(i);
        m[c][order(fh, i)]++;
    }
    ll ans = 0;
    string sh = s.substr(n, 2*n);
    reverse(sh.begin(), sh.end());
    for (int i = 0; i < (1 << n); i++) {
        int c = __builtin_popcount(i);
        ans += m[c][order(sh, i)];
    }
    
    cout << ans << endl;
    
    return 0;
}
