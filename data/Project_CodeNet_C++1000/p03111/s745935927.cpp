#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int n, A, B, C;
int l[10];

int dfs(int cur, int a, int b, int c) {
    if (cur == n) {
        if (min({a, b, c}) > 0) return abs(a - A) + abs(b - B) + abs(c - C) - 30;
        else return INF;
    }
    int ret0 = dfs(cur + 1, a, b, c);
    int ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
    int ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
    int ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;

    return min({ret0, ret1, ret2, ret3});
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> A >> B >> C;
    rep(i, n) cin >> l[i];

    cout << dfs(0, 0, 0, 0) << endl;

    return 0;
}