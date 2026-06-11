#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
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
    vector<int> a(N);
    double res = 0.0;
    REP(i, N) {
        cin >> a[i];
        res += a[i];
    }
    double ans = res / N;
    int aa;
    double b = 1000000;
    reverse(a.begin(), a.end());
    REP(i, N) {
        if(abs(a[i] - ans) <= b) {
            b = abs(a[i] - ans);
            aa = i;
        }
    }
    cout << N - aa - 1 << endl;
    return 0;
}