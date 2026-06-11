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
    ll N, M;
    str S, T;
    cin >> N >> M >> S >> T;
    ll ans;
    while (M > 0) {
        ans = N % M;
        N = M;
        M = ans;
    }
    const ll gcd = N;
    ll n = S.size() / gcd, m = T.size() / gcd;
    ll count = 0;
    rep(i, gcd) {
        ll a = i * n, b = i * m;
        if (S[a] == T[b]) {
            count++;
        }
        else {
            break;
        }
    }
    if (count == gcd) {
        cout << S.size() * T.size() /gcd << endl;
    }
    else {
        cout <<-1 << endl;
    }
}