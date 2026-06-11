// 7/8
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

struct state {
    int i, j, k;
    state(int i, int j, int k) : i(i), j(j), k(k) { }
    bool operator<(const state a) const { return state(*this).i < a.i; }
};

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    // priority_queue<ll> a, b, c;
    // rep(i, X) a.push(A[i]);
    // rep(i, Y) b.push(B[i]);
    // rep(i, Z) c.push(C[i]);

    // ll res = a.top() + b.top() + c.top();
    // cout << res << endl;
    // if (a.size() > 1) a.pop();
    // if (b.size() > 1) b.pop();
    // if (c.size() > 1) c.pop();
    // rep(i, K) {
    //     ll next;
    //     ll cake;
    //     if (!a.empty()) {
    //         next = a.top();
    //     }
    //     if (!b.empty()) {
    //     }
    // }

    // int ia, ib, ic;
    // ia = ib = ic = 0;
    // ll res = A[0] + B[0] + C[0];
    // priority_queue<ll> ans;
    // ans.push(res);

    // for (int i = 1; i < X; i++) {
    //     ll now = A[i] + B[0] + C[0];
    //     ans.push(now);

    //     ll comp;
    //     rep(j, Y) {
    //         rep(k, Z) {
    //             comp = A[i] + B[j] + C[k];
    //             if (now >= comp) {
    //                 ans.push(comp);
    //             }
    //             else {
    //                 break;
    //             }
    //         }
    //     }

    //     if (ans.size() >= 3000) break;
    // }

    // while (!ans.empty()) {
    //     cout << ans.top() << endl;
    //     ans.pop();
    // }

    vector<vector<vector<bool>>> used(X, vector<vector<bool>>(Y, vector<bool>(Z, false)));
    priority_queue<pair<ll, state>> que;
    que.push({A[0]+B[0]+C[0], state(0, 0, 0)});
    used[0][0][0] = true;
    int num = 0;

    while (num < K) {
        ll ans = que.top().first;
        state s = que.top().second;
        cout << ans << endl;
        que.pop();
        num++;

        int ni = s.i + 1;
        int nj = s.j + 1;
        int nk = s.k + 1;

        if (ni != X && !used[ni][s.j][s.k]) {
            que.push({A[ni] + B[s.j] + C[s.k], state(ni, s.j, s.k)});
            used[ni][s.j][s.k] = true;
        }
        if (nj != Y && !used[s.i][nj][s.k]) {
            que.push({A[s.i] + B[nj] + C[s.k], state(s.i, nj, s.k)});
            used[s.i][nj][s.k] = true;
        }
        if (nk != Z && !used[s.i][s.j][nk]) {
            que.push({A[s.i] + B[s.j] + C[nk], state(s.i, s.j, nk)});
            used[s.i][s.j][nk] = true;
        }
    }
}