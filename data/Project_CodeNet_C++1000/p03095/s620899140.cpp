#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

const int64_t MOD = 1000000007;

int main() {
    int N; string S;
    cin >> N >> S;
    int64_t ans = 0;
    map<char, int> mp;
    for(auto &t : S) {
        int64_t tmp = 1;
        for(char c = 'a'; c <= 'z'; ++c) {
            if(t != c) tmp *= (mp[c] + 1), tmp %= MOD;
        }
        ans += tmp;
        ans %= MOD;
        mp[t]++;
    }
    cout << ans << '\n';
    return 0;
}
