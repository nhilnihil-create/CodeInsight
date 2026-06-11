#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

#define M 998244353

ll pw(ll a, ll b) {
    if (b == 0)
        return 1;
    ll x = pw(a, b/2);
    x = (x*x) % M;
    if (b%2)
        x = (x*a) % M;
    return x;
}

ll c[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = gi();
    ll a = gi();
    ll b = gi();
    ll k = gli();

    c[0] = 1;
    for (ll i = 0; i < n; i++) {
        ll x = (c[i] * (n-i)) % M;
        c[i+1] = (x * pw(i+1, M-2)) % M;
    }

    ll res = 0;
    for (ll i = 0; i <= n; i++) {
        ll r = k - a*i;
        ll j = r/b;
        if (r >= 0 && r%b == 0 && j <= n) {
            res += (c[i] * c[j]) % M;
            res %= M;
        }
    }

    cout << res << endl;

    return 0;
}
