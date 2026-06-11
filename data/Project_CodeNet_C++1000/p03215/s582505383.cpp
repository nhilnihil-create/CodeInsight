#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    REP(i, 0, N) cin >> A[i];

    vector<ll> S;
    REP(i, 0, N) {
        S.push_back(A[i]);
        REP(j, i + 1, N) {
            S.push_back(S.back() + A[j]);
        }
    }

    vector<vector<int>> sbits(S.size(), vector<int>(40, 0));
    REP(i, 0, S.size()) {
        ll tmp = S[i];
        REP(j, 0, 40) {
            sbits[i][j] = tmp & 1;
            tmp >>= 1;
            if (tmp == 0) break;
        }
    }

    ll ans = 0;
    vector<int> idxs(S.size());
    iota(ALL(idxs), 0);
    for (int i = 39; i >= 0; i--) {
        // cout << "# bit : " << i << endl;
        vector<int> next;
        for (auto j : idxs) if (sbits[j][i]) {
            next.push_back(j);
            // cout << "--> " << S[j] << endl;
        }
        if ((int)next.size() >= K) {
            // cout << "--> found more than K" << endl;
            idxs = next;
            ans += (1LL << i);
        } else {
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}
