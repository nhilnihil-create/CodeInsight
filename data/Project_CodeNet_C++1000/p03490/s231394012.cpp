#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1LL << 40;
#define INF 1 << 31;
#define MOD 1000000007;
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define prique priority_queue
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vector<int>> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct edge {
    int to, cost;
};

bool dp[2][8001][16001];

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    x += 8000;
    y += 8000;
    vi xy[2];
    int tmp = 0, cnt = 0;
    rep(i, s.size()) {
        if(s[i] == 'T') {
            xy[cnt % 2].push_back(tmp);
            tmp = 0;
            cnt++;
        } else {
            tmp++;
        }
    }
    xy[cnt % 2].push_back(tmp);
    x -= xy[0][0];
    rep(k, 2) rep(i, 8001) rep(j, 16001) { dp[k][i][j] = false; }
    dp[0][1][8000] = true;
    dp[1][0][8000] = true;
    rep(k, 2) REP(i, k == 0 ? 1 : 0, xy[k].size()) {
        rep(j, 16001) {
            if(0 <= j + xy[k][i] <= 16000)
                dp[k][i + 1][j + xy[k][i]] |= dp[k][i][j];
            if(0 <= j - xy[k][i] <= 16000)
                dp[k][i + 1][j - xy[k][i]] |= dp[k][i][j];
        }
    }
    if(dp[0][xy[0].size()][x] & dp[1][xy[1].size()][y]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    // rep(i, 2) {
    //     rep(j, xy[i].size()) { cout << xy[i][j] << " "; }
    //     cout << endl;
    // }
}
