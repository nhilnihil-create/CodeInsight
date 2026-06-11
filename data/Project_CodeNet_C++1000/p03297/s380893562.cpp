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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int f(ll A, ll B, ll C, ll D) {
    bool answer = true;
    answer &= (A >= B);
    answer &= (D >= B);
    if (C >= B) return answer;

    ll g = __gcd(D, B);
    ll x = (A % g) + C - (C % g);
    if (x <= C) x += g;
    answer &= (x >= B);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;

        bool answer = f(A, B, C, D);

        cout << (answer ? "Yes" : "No") << endl;
    }

    return 0;
}

