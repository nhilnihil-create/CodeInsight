#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;
const int N = 1e6;

class LinearSieve {
    public:
        vector<int> lp, pr;
        LinearSieve() {}
        LinearSieve(int n) {
            lp.resize(n + 1);
            lp[0] = -1, lp[1] = -1;
            init(n);
        }

        void init(int x) {
            FOR (i, 2, x + 1) {
                if (lp[i] == 0) {
                    lp[i] = i;
                    pr.push_back(i);
                }
                for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && (ll)i * pr[j] <= x; ++j) {
                    lp[i * pr[j]] = pr[j];
                }
            }
        }

        bool isPrime(int x) {
            return lp[x] == x;
        }

        vector<int> factorList(int x) {
            vector<int> res;
            while (x != 1) {
                res.push_back(lp[x]);
                x /= lp[x];
            }

            return res;
        }

        vector<pair<int, int> > factorize(int x) {
            vector<int> p = factorList(x);
            if (p.size() == 0) return {};
            vector<pair<int, int> > res(1, make_pair(p[0], 0));
            rep (i, p.size()) {
                if (res.back().first == p[i]) {
                    res.back().second++;
                } else {
                    res.emplace_back(p[i], 1);
                }
            }

            return res;
        }
};

int main() {
    LinearSieve ls = LinearSieve(N);
    vector<int> sum(N + 10);
    FOR (i, 1, N + 1) if (ls.isPrime(i) && ls.isPrime((i + 1) / 2)) sum[i]++;
    FOR (i, 1, N + 1) sum[i] += sum[i - 1];
    int q;
    cin >> q;
    rep (_, q) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

    return 0;
}