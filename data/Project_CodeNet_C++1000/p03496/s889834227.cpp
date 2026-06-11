
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N;
    cin >> N;

    int a[N];
    ll m = inf, M = -inf;
    int mi, Mi;
    REP(i, N) {
        cin >> a[i];
        if (m > a[i]) {
            m = a[i];
            mi = i;
        }

        if (M < a[i]) {
            M = a[i];
            Mi = i;
        }
    }

    ++mi; ++Mi;

    if (m * M < 0) {
        cout << 2 * N - 1 << endl;
        if (abs(m) > abs(M)) {
            REP(i, N) {
                cout << mi << " " << i+1 << endl;
            }
            m += m;
            M += m;
        } else {
            REP(i, N){
                cout << Mi << " " << i+1 << endl;
            }
            m += M;
            M += M;
        }
    } else {
        cout << N - 1 << endl;
    }


    if (m >= 0) {
        REP(i, N - 1) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        REP(i, N - 1) {
            cout << N - i << " " << N - i - 1 << endl;
        }
    }

}
