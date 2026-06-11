#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

struct LongestCommonSubsequence {
private:
    string s, t;
    vector<vector<int>> dp;
    
public:
    LongestCommonSubsequence(const string &_s, const string &_t) : s(_s), t(_t) {}
    
    int build() {
        int ls = s.length(), lt = t.length();
        dp.resize(ls + 1, vector<int>(lt + 1, 0));
        for(int i = 0; i < ls; i++) {
            for(int j = 0; j < lt; j++) {
                if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            }
        }
        return dp[ls][lt];
    }
    
    string restore() {
        int x = s.length(), y = t.length();
        string ans = "";
        while((x > 0) && (y > 0)) {
            if (dp[x][y] == dp[x - 1][y]) {
                x--;
            }
            else if (dp[x][y] == dp[x][y - 1]) {
                y--;
            }
            else {
                x--;
                y--;
                ans += s[x];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    string s, t;
    cin >> s >> t;
    LongestCommonSubsequence lcs(s, t);
    lcs.build();
    cout << lcs.restore() << endl;
    return 0;
}
