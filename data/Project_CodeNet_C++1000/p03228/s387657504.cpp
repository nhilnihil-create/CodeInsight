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
    ll A, B;
    int K;
    cin >> A >> B >> K;
    REP(i, K) {
        if(i % 2 == 0) {
            if(A % 2 == 1) {
                A--;
            }
            B += A / 2;
            A = A / 2;
        } else {
            if(B % 2 == 1) {
                B--;
            }
            A += B / 2;
            B = B / 2;
        }
    }
    cout << A << " " << B << endl;
    return 0;
}