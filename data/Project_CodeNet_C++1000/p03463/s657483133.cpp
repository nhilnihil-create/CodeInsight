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

long long gcd(long long a, long long b) {
    for(;;) {
        if(a == 0)
            return b;
        b %= a;
        if(b == 0)
            return a;
        a %= b;
    }
}

long long lcm(long long a, long long b) {
    long long temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if((B - A) % 2 == 0) {
        cout << "Alice" << endl;
        return 0;
    } else {
        cout << "Borys" << endl;
        return 0;
    }
    return 0;
}