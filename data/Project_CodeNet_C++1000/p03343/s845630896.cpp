#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Q;
    cin >> N >> K >> Q;

    vi a(N), order(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        order[i] = i;
    }

    auto sort_inx = [&a](vi& v) {
        sort(all(v), [&](int i, int j) {
            return a[i] < a[j];
        });
    };

    sort_inx(order);

    int ans = INT_MAX;
    for (int l = 0; l + Q <= N; l++) {
        vi take;
        auto store = [&](vi& cur) {
            sort_inx(cur);
            for (int t = 0; t < int(cur.size()) - K + 1; t++)
                take.push_back(cur[t]);
            cur.clear();
        };

        vi cur;
        for (int i = 0; i < N; i++) {
            if (a[i] < a[order[l]]) {
                store(cur);
            } else {
                cur.push_back(i);
            }
        }
        store(cur);

        sort_inx(take);
        if (take.size() >= Q) {
            ans = min(ans, a[take[Q - 1]] - a[take[0]]);
        }
    }

    cout << ans << endl;
    return 0;
}

