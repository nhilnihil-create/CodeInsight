#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    long long ans = 0;
    vector<int> cnt(n+1);
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'A') cnt[i+1] = cnt[i]+1;
        else if (i && s[i-1] == 'B' && s[i] == 'C') {
            cnt[i+1] = cnt[i-1];
            ans += cnt[i+1];
        }
        else cnt[i+1] = 0;
    }
    cout << ans << endl;
    return 0;
}
