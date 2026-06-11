#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    ll N, M;

    cin >> N >> M;

    vector<p> C, ans;
    vector<vector<ll>> H(N + 1);

    ll P, Y;

    rep(i, M) {
        cin >> P >> Y;
        C.emplace_back(P, Y);
        H[P].push_back(Y);
    }

    rep(i, N + 1) {
        sort(H[i].begin(), H[i].end());
    }


    rep(i, M) {
        P = C[i].first;      
        Y = lower_bound(H[P].begin(), H[P].end(), C[i].second) - H[P].begin() + 1;
        ans.emplace_back(P, Y);
    }

    char fillSaved = cout.fill('0');

    rep(i, M) {
        cout << setw(6) << ans[i].first << setw(6) << ans[i].second << endl;
    }

    cout.fill(fillSaved);

    return 0;
}



ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}