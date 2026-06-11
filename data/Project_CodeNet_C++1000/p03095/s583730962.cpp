#include <bits/stdc++.h>
using namespace std;

int main(){
    const int64_t mod = 1e9 + 7;
    int64_t n, ans = 1; string s; cin >> n >> s;
    vector<int> cnt(26, 0);
    for (auto i = 0; i < n; i++) cnt[s[i] - 'a']++;
    for (auto i = 0; i < 26; i++) ans = (ans * (cnt[i] + 1)) % mod;
    cout << ans - 1 << endl;
    return 0;
}