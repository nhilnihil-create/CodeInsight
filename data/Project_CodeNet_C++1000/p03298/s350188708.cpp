#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    
    long long ans = 0;
    map<pair<string, string>, long long> mp;
    
    for (int s = 0; s < (1<<n); s++) {
        string r = "", b = "";
        for (int i = 0; i < n; i++) {
            if (s & (1<<i)) r.push_back(str[i]);
            else b.push_back(str[i]);
        }
        reverse(b.begin(), b.end());
        mp[make_pair(r, b)]++;
    }
    
    for (int s = 0; s < (1<<n); s++) {
        string r = "", b = "";
        for (int i = 0; i < n; i++) {
            if (s & (1<<i)) r.push_back(str[i + n]);
            else b.push_back(str[i + n]);
        }
        reverse(b.begin(), b.end());
        ans += mp[make_pair(b, r)];
    }
    
    cout << ans << endl;
    return 0;
}