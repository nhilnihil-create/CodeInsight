#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    
    vector<int> cnt(3, 0);
    rep(i, N) {
        if (s[i][0] == 'B' && s[i].back() == 'A') {
            ++cnt[0];
        } else {
            if (s[i][0] == 'B') ++cnt[1];
            else if (s[i].back() == 'A') ++cnt[2];
        }
    }
    int ans;
    if (cnt[1] || cnt[2]) {
        ans = cnt[0] + min(cnt[1], cnt[2]);
    } else {
        ans = max(0, cnt[0] - 1);
    }
    rep(i, N) {
        REP(j, s[i].size()) {
            if (s[i][j - 1] == 'A' && s[i][j] == 'B') ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
