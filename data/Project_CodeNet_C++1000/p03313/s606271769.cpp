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

    int N;
    cin >> N;

    vi a(1 << N);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    vi m1(1 << N, -1), m2(1 << N, -1);
    m1[0] = 0;

    vi c(1 << N);

    for (int i = 1; i < a.size(); i++) {
        m1[i] = i;
        for (int j = 0; j < N; j++) if (i & (1 << j)) {
            for (int cinx : { m1[i ^ (1 << j)], m2[i ^ (1 << j)] }) {
                if (cinx == -1) continue;
                if (cinx == m1[i] || cinx == m2[i]) continue;

                if (a[cinx] >= a[m1[i]]) {
                    m2[i] = m1[i];
                    m1[i] = cinx;
                }
                else if (m2[i] == -1 || a[cinx] > a[m2[i]]) {
                    m2[i] = cinx;
                }
            }
        }
        c[i] = a[m1[i]] + a[m2[i]];
    }

    for (int i = 1; i < c.size(); i++) {
        c[i] = max(c[i], c[i-1]);
        cout << c[i] << "\n";
    }

    return 0;
}

