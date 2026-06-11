#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int N;
    cin >> N;
    vector<double> t(N), v(N);
    REP(i, N) { cin >> t[i]; }
    REP(i, N) { cin >> v[i]; }
    int T = accumulate(t.begin(), t.end(), 0);
    // maxv i t=iのときの最大
    vector<double> maxv(2 * T + 1, 10000000);
    int time = 1;
    int nowT = 0;
    REP(i, N) {
        for(int ti = 0; ti < t[i]; ti++) {
            int t1 = nowT + ti * 2;
            int t2 = nowT + ti * 2 + 1;
            maxv[t1] = min(maxv[t1], v[i]);
            maxv[t2] = min(maxv[t2], v[i]);
        }
        nowT += t[i] * 2;
        maxv[nowT] = min(maxv[nowT], v[i]);
    }
    maxv[0] = 0;
    maxv[2 * T] = 0;
    // cout << "T " << T << endl;
    for(int i = 1; i <= 2 * T + 1; i++) {
        maxv[i] = min(maxv[i], maxv[i - 1] + 0.5);
    }
    for(int i = 2 * T - 1; i >= 0; i--) {
        maxv[i] = min(maxv[i], maxv[i + 1] + 0.5);
    }
    double ans = 0;
    for(int i = 0; i < 2 * T; i++) {
        // cout << i << ":::" << maxv[i] << endl;
        ans += (maxv[i] + maxv[i + 1]) / 2 / 2;
    }
    printf("%.4f\n", ans);
    return 0;
}