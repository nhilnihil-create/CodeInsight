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
 
typedef long long ll;
 
typedef long double ld;
 
using namespace std;
 
const ll maxn = 1e6 + 100;

ll n, m, k, t;

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c, d;
    string s;
    cin >> s;
    n = s.length();
    ll cnta = 0, ans = 0;
    for (q = 0; q < n; q++) {
        if (s[q] == 'A') {
            cnta++;
        }
        else {
            if (q < n - 1) {
                if (s[q] == 'B' && s[q + 1] == 'C') {
                    ans += cnta;
                    q++;
                }
                else {
                    cnta = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}