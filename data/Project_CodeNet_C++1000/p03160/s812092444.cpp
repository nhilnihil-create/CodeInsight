#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000007;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> h;
vector<ll> memo;

ll rec(int i) {
    if (i == 0) return 0;

    if (memo[i] != -1) return memo[i];
    ll res = INF;
    chmin(res, rec(i-1) + abs(h[i] - h[i-1]));
    if (i > 1) chmin(res, rec(i-2) + abs(h[i] - h[i-2]));
    return memo[i] = res;
}

int main() {
    memo.assign(100100, -1);
    int N; cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i) cin >> h[i];
    cout << rec(N-1) << endl;
    return 0;
}