#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> S(N+1, 0);
    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        ++S[l], --S[r+1];
    }
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        S[i+1] += S[i];
        if (S[i+1] == M) ++res;
    }
    cout << res << endl;
    return 0;
}