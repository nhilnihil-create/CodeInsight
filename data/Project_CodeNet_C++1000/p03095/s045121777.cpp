#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define pld pair <ld, ld>
#define all(a) a.begin(), a.end()
#define vvl vector <vector <ll> >
#define cld complex <double>

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;

ll n, m, k, t;

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n;
    string s;
    cin >> s;
    map <ll, ll> C;
    for (q = 0; q < s.length(); q++) {
        C[s[q]]++;
    }
    ll ans = 1;
    for (auto p : C) {
        ans *= (p.second + 1);
        ans %= mod;
    }
    cout << (ans - 1 + mod) % mod;
    return 0;
}
