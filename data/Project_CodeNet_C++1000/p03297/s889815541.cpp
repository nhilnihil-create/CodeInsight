#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
constexpr ll mod = 1000000007;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ll t, a, b, c, d;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> a >> b >> c >> d;
        ll g = gcd(b, d);
        ll l = (((a - b) % g) + b) - g;
        if (a < b || d < b || c < l) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
