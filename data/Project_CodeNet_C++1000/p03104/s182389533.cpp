#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll f(ll n) {
    switch(n % 4) {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        case 3:
            return 0;
    }
}

int main()
{
    ll A, B; cin >> A >> B;
    cout << (f(A-1) ^ f(B)) << endl;
    return 0;
}