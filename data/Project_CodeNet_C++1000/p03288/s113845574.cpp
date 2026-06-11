#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

ll binPow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

ll binPowMod(ll a, ll b, ll m) {
    ll ans = 1;
    a %= m;
    while(b > 0) {
        if(b & 1) ans *= a % m;
        a *= a % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    if(n < 1200) cout << "ABC\n";
    else if(n < 2800) cout << "ARC\n";
    else cout << "AGC\n";
    return 0;
}
