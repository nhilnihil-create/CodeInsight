#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int n;
ll z, w;
vector<int> a;
vector<vector<ll>> memo(2020, vector<ll>(2, -1LL));

ll dfs(int i, int turn, ll x, ll y) {
    if(i == n) {
        return llabs(x - y);
    }
    if(memo[i][turn] >= 0) {
        return memo[i][turn];
    }
    ll res;
    if(turn == 0) {
        res = -LLINF;
        for(int j = i + 1; j <= n; j++) {
            chmax(res, dfs(j, 1, a[j - 1], y));
        }
        return memo[i][turn] = res;
    } else {
        res = LLINF;
        for(int j = i + 1; j <= n; j++) {
            chmin(res, dfs(j, 0, x, a[j - 1]));
        }
        return memo[i][turn] = res;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> z >> w;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << dfs(0, 0, z, w) << endl;
}