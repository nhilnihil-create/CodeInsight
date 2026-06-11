
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

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
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

    int dp[N + 1];
    REP(i, N + 1) dp[i] = inf;
    dp[0] = 0;

    REP(i, N) {
        // 1
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        // 6^n
        int s = 6;
        while(i + s <= N) {
            dp[i + s] = min(dp[i + s], dp[i] + 1);
            s *= 6;
        }

        // 9^n
        s = 9;
        while(i + s <= N) {
            dp[i + s] = min(dp[i + s], dp[i] + 1);
            s *= 9;
        }
    }

    print(dp[N]);

}
