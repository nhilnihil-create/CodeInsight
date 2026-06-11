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
 
    int N; ll C;
    cin >> N >> C;
 
    vll x(N); vi v(N);
    vll pref(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
        pref[i + 1] = pref[i] + v[i];
    }
 
    vll rtL(N + 1), rtR(N + 1);
    for (int i = 0; i < N; i++) {
        rtL[i] = pref[i+1] - 2 * x[i];
        rtR[i] = pref[N] - pref[i] - 2 * (C - x[i]);
    }
 
    vll left(N + 1), right(N + 1);
    for (int i = 0; i < N; i++) {
        left[i] = max(rtL[i], i ? left[i-1] : 0);
    }
    for (int i = N - 1; i >= 0; i--) {
        right[i] = max(rtR[i], right[i+1]);
    }
 
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, rtL[i] + x[i] + right[i+1]);
        ans = max(ans, rtR[i] + C - x[i] + (i ? left[i-1] : 0));
    }
    cout << ans << endl;
 
    return 0;
}