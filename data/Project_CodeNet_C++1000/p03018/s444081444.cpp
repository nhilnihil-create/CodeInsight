#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int cnt = 0;
    vector<int> A_num(s.size(), -1);
    rep(i, s.size()) {
        if (s[i] == 'A') {
            A_num[i] = cnt;
            ++cnt;
        }
    }
    vector<int> A_ans(cnt, -1);
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (s[i] != 'A') continue;
        int BC_cnt = 0;
        for (int j = i + 1; j < (int)s.size() - 1; ++j) {
            if (s[j] == 'A') {
                A_ans[A_num[i]] = BC_cnt + A_ans[A_num[j]];
                break;
            }
            if (s[j] == 'C') break;
            if (s[j + 1] == 'C') {
                ++BC_cnt;
                ++j;
            } else {
                break;
            }
        }
        if (A_ans[A_num[i]] == -1) A_ans[A_num[i]] = BC_cnt;
    }
    long long ans = 0;
    rep(i, cnt) ans += A_ans[i];
    cout << ans << endl;
    return 0;
}
