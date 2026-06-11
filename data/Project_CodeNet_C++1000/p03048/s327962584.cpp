#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll mod = 1000000007;
const double pi = 3.14159265358979;

int main() {
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll cnt = 0;
    rep(r, 3001) {
        rep(g, 3001) {
            ll b = (N - r * R - g * G) % B, ans = N - r * R - g * G;
            if (ans >= 0 && b == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}