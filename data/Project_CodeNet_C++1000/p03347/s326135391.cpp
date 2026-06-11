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

void print(const std::vector<ll> &v) {
    std::for_each(v.begin(), v.end(), [](ll x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main(void) {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) { cin >> A[i]; }
    REP(i, N) {
        if(A[i] > i) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    REP(i, N - 1) {
        if(A[i] + 1 == A[i + 1]) {
            ans++;
        } else if(A[i] == A[i + 1]) {
            if(A[i] > 1) {
                // cout << "p" << endl;
                ans += A[i];
            } else if(A[i] == 1) {
                ans++;
            }
        } else if(A[i] > A[i + 1]) {
            if(A[i + 1] > 0) {
                ans += A[i + 1];
            }
        } else {
            // cout << "hjoge" << endl;
            cout << -1 << endl;
            return 0;
        }
    }
    //狭義増加してるところは一回の更新で行ける
    //増加じゃないところは++
    cout << ans << endl;
    return 0;
}