#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    
    string t0;
    rep(i, s.size()) {
        if (s[i] != 'x') t0.push_back(s[i]);
    }
    string t1 = t0;
    reverse(t1.begin(), t1.end());
    if (t0 != t1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> S;
    int cnt = 0;
    rep(i, s.size()) {
        if (s[i] == 'x') {
            ++cnt;
        } else {
            S.push_back(cnt);
            cnt = 0;
        }
    }
    S.push_back(cnt);
    vector<int> T = S;
    reverse(T.begin(), T.end());
    int ans = 0;
    rep(i, S.size()) ans += max(S[i], T[i]) - S[i];
    cout << ans << endl;
    return 0;
}
