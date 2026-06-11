#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi a(N), b(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];

    int res = 0;
    for (int bit = 0; bit < 29; bit++) {
        int M = 1 << (bit + 1);

        vi av;
        for (int v : a) {
            av.push_back(v & (M - 1));
        }
        sort(all(av), greater<int>());

        vi bv;
        for (int v : b) {
            bv.push_back(v & (M - 1));
        }
        sort(all(bv));

        // count a + b >= 2^b mod 2^(b+1)
        // b in [M/2 - a, M - a)
        ll app = 0;

        int i = 0, j = 0, k = 0;
        for (int v : av) {
            while (i < N && v + bv[i] < M/2) i++;
            while (j < N && v + bv[j] < M) j++;
            while (k < N && v + bv[k] < 3*M/2) k++;
            app += j - i + N - k;
        }

        if (app&1) res ^= 1 << bit;
    }

    cout << res << endl;
    return 0;
}

