#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

constexpr int mod = 1e9 + 7;

int ModPow(int x, int y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    long long a = ModPow(x, y / 2);
    if (y & 1) return a * a % mod * x % mod;
    else return a * a % mod;
}

int main() {
    string S;
    cin >> S;
    
    int hatena_cnt = 0;
    rep(i, S.size()) {
        if (S[i] == '?') ++hatena_cnt;
    }
    vector<vector<int>> cnt(S.size(), vector<int>(4, 0));
    if (S[0] == '?') cnt[0][3] = 1;
    else cnt[0][S[0] - 'A'] = 1;
    REP(i, S.size()) {
        rep(j, 4) cnt[i][j] = cnt[i - 1][j];
        if (S[i] == '?') ++cnt[i][3];
        else ++cnt[i][S[i] - 'A'];
    }
    
    int ans = 0;
    rep(i, S.size()) {
        if (S[i] == 'A' || S[i] == 'C') continue;
        if (i == 0 || i == S.size() - 1) continue;
        
        int A = cnt[i - 1][0];
        int C = cnt[S.size() - 1][2] - cnt[i][2];
        int hatena_front = cnt[i - 1][3];
        int hatena_back = cnt[S.size() - 1][3] - cnt[i][3];
        long long res = 0;
        if (S[i] == 'B') {
            res += (long long)ModPow(3, hatena_cnt) * A * C;
            res += (long long)ModPow(3, hatena_cnt - 1) * hatena_front * C;
            res += (long long)ModPow(3, hatena_cnt - 1) * A * hatena_back;
            res += (long long)ModPow(3, hatena_cnt - 2) * hatena_front * hatena_back;
            ans = (ans + res) % mod;
        } else {
            res += (long long)ModPow(3, hatena_cnt - 1) * A * C;
            res += (long long)ModPow(3, hatena_cnt - 2) * hatena_front * C;
            res += (long long)ModPow(3, hatena_cnt - 2) * A * hatena_back;
            res += (long long)ModPow(3, hatena_cnt - 3) * hatena_front * hatena_back;
            ans = (ans + res) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
