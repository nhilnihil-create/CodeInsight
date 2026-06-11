#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 2;

signed main() {
    string S;
    cin >> S;
    if(S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }
    if(S.length() < 26) {
        bool used[26] = {};
        for(int i = 0; i < S.length(); i++) {
            used[S[i] - 'a'] = true;
        }
        string ans = S;
        for(int i = 0; i < 26; i++)
            if(!used[i]) {
                ans += (char)(i + 'a');
                cout << ans << endl;
                return 0;
            }
    }
    int prev = -1;
    for(int i = 25; i >= 0; i--) {
        if(S[i] > prev) {
            prev = S[i];
            continue;
        }
        string ans = S.substr(0, i);
        for(int j = 25; j > i; j--)
            if(S[j] > S[i]) {
                ans += S[j];
                cout << ans << endl;
                return 0;
            }
    }
    return 0;
}
