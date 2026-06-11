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

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    scanf("%d", &N);

    char S[int(1.1e6)];
    scanf(" %s", S);

    int Q;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int K;
        scanf("%d", &K);

        ll d = 0, dm = 0, m = 0, dmc = 0;
        for (int i = 0; i < N; i++) {
            if (i >= K) {
                char r = S[i - K];
                if (r == 'D') { dm -= m; d--; }
                else if (r == 'M') { m--; }
            }
            char c = S[i];
            if (c == 'D') d++;
            else if (c == 'M') { dm += d; m++; }
            else if (c == 'C') dmc += dm;
        }
        printf("%lld\n", dmc);
    }

    return 0;
}

