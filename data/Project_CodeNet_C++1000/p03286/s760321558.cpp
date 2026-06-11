#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUM(c) accumulate(ALL(c), 0)
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1 << 30;
// const ll INF = 1LL << 62;
// --------------------------------------------------------


ll _pow(ll x, ll n) {
    ll res = 1;
    REP(_, n) res *= x;
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    ll N; cin >> N;
    const ll D = 32;

    string ans = "";
    FOR(i, 0, D + 1) {
        if (N % _pow(2, i + 1) != 0) {
            ans = '1' + ans;
            N -= _pow(-2, i);
        } else {
            ans = '0' + ans;
        }
    }

    int x = ans.find('1');
    if (x == -1) {
        ans = "0";
    } else {
        ans = ans.erase(0, x);
    }
    cout << ans << '\n';

    return 0;
}
