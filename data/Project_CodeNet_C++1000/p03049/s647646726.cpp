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

    ll N;
    cin >> N;

    string S;
    ll cnt = 0, cnt1 = 0, cnt2 = 0, ans = 0 ;

    rep(i, N) {
        cin >> S;
        if (S[0] == 'B' && S[S.size() - 1] == 'A') cnt++;
        else if (S[S.size() - 1] == 'A') cnt1++;
        else if (S[0] == 'B') cnt2++;

        rep(i, S.size() -1) {
            if (S[i] == 'A' && S[i + 1] == 'B') {
                ans++;
            }
        }
    }

    if (cnt1 + cnt2 > 0) ans += cnt + min(cnt1, cnt2);
    else ans += max(cnt - 1, cnt * 0);

    cout << max(ans, ans * 0);

    return 0;

}



ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}