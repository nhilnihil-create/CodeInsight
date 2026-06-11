#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> a;
vector<vector<int>> edge;
vector<int> dp;
vector<int> res;

void dfs(int i = 0, int p = -1) {
    int l = LB(dp, a[i]);
    int tmp = dp[l];
    dp[l] = a[i];
    res[i] = LB(dp, INT_MAX);
    for (auto &j : edge[i]) {
        if (j == p) continue;
        dfs(j, i);
    }
    dp[l] = tmp;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    REP(i, X) cin >> A[i];
    REP(i, Y) cin >> B[i];
    REP(i, Z) cin >> C[i];
    SORTR(A);
    SORTR(B);
    SORTR(C);
    using T = tuple<ll, int, int, int>;
    priority_queue<T> pq;
    set<T> st;
    pq.emplace(A[0] + B[0] + C[0], 0, 0, 0);
    st.emplace(A[0] + B[0] + C[0], 0, 0, 0);
    REP(x, K) {
        ll sum;
        int i, j, k;
        tie(sum, i, j, k) = pq.top();
        pq.pop();
        cout << A[i] + B[j] + C[k] << endl;
        if (i < X - 1 && !st.count(T(A[i + 1] + B[j] + C[k], i + 1, j, k))) {
            pq.emplace(A[i + 1] + B[j] + C[k], i + 1, j, k);
            st.insert(T(A[i + 1] + B[j] + C[k], i + 1, j, k));
        }
        if (j < Y - 1 && !st.count(T(A[i] + B[j + 1] + C[k], i, j + 1, k))) {
            pq.emplace(A[i] + B[j + 1] + C[k], i, j + 1, k);
            st.insert(T(A[i] + B[j + 1] + C[k], i, j + 1, k));
        }
        if (k < Z - 1 && !st.count(T(A[i] + B[j] + C[k + 1], i, j, k + 1))) {
            pq.emplace(A[i] + B[j] + C[k + 1], i, j, k + 1);
            st.insert(T(A[i] + B[j] + C[k + 1], i, j, k + 1));
        }
    }

    return 0;
}