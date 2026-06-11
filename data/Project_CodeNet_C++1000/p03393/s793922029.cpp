#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    
    if (S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }
    if (S.size() == 26) {
        bool x = false;
        string s = S;
        string T = "";
        do {
            if (x) {
                T = s;
                break;
            }
            x = true;
        } while (next_permutation(s.begin(), s.end()));
        string ans = "";
        rep(i, S.size()) {
            ans.push_back(T[i]);
            if (S[i] != T[i]) break;
        }
        cout << ans << endl;
    }
    vector<int> cnt(26, 0);
    rep(i, S.size()) ++cnt[S[i] - 'a'];
    rep(i, 26) {
        if (!cnt[i]) {
            char c = 'a' + i;
            cout << S << c << endl;
            return 0;
        }
    }
}
