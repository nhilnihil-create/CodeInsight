#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int t;
ll a,b,c,d;

void solve();

void input() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        solve();
    }
}

void solve() {
    if (a < b) {
        cout << "No" << endl;
        return;
    }

    if (d < b) {
        cout << "No" << endl;
        return;
    }

    if (c >= b) {
        cout << "Yes" << endl;
        return;
    }

    //a >= b, c < b, d >= b
    ll g = __gcd(b,d);
    cout << (b - g + (a % g) > c ? "No":"Yes") << endl;
}

int main(int argc, char *argv[]){
    input();
    // solve();
    return 0;
}
