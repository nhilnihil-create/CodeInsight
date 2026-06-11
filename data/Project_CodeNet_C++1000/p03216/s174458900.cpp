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
    cin >> N;

    string S;
    cin >> S;

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int K;
        cin >> K;

        ll d = 0, dm = 0, m = 0, dmc = 0;
        for (int i = 0; i < N; i++) {
            if (i >= K) switch (S[i - K]) {
                case 'D': dm -= m; d--; break;
                case 'M': m--; break;
                case 'C': break;
                default: break;
            }
            switch(S[i]) {
                case 'D': d++; break;
                case 'M': dm += d; m++; break;
                case 'C': dmc += dm; break;
                default: break;
            }
        }
        cout << dmc << "\n";
    }

    return 0;
}

