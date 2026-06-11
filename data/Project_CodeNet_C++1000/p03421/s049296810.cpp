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

    int N, A, B;
    cin >> N >> A >> B;

    if (A * ll(B) < N || A + B - 1 > N) {
        cout << -1 << endl;
        return 0;
    }

    int v = 0, pr = N - A;
    for (int i = 0; i < A; i++) {
        int desc = 1 + min(pr, B - 1);
        for (int j = v + desc; j > v; j--) {
            cout << j << " ";
        }
        v += desc;
        pr -= desc - 1;
    }
    cout << endl;

    return 0;
}

