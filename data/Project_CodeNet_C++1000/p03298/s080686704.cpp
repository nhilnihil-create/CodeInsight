#include <bits/stdc++.h>
using namespace std;
using strings = pair<string, string>;

int main() {
    int n;
    long long ans = 0;
    string s;
    cin >> n >> s;
    
    map<strings, long long> mp;
    
    for (int bit = 0; bit < (1<<n); bit++) {
        string r = "", b = "";
        for (int i = 0; i < n; i++) {
            if (bit&(1<<i)) r = r + s[i];
            else b = b + s[i];
        }
        reverse(b.begin(), b.end());
        mp[make_pair(r, b)]++;
    }
    
    for (int bit = 0; bit < (1<<n); bit++) {
        string r = "", b = "";
        for (int i = 0; i < n; i++) {
            if (bit&(1<<i)) r = r + s[i+n];
            else b = b + s[i+n];
        }
        reverse(r.begin(), r.end());
        strings t = make_pair(r, b);
        if (mp.count(t)) ans += mp[t];
    }
    
    cout << ans << endl;
    return 0;
}