// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

ll cur, b, c, d;

void solve() {
    scanf("%lld %lld %lld %lld", &cur, &b, &c, &d);

    if (d < b) {
        printf("No\n");
        return;
    }

    {
        ll k = max(1ll, (cur - c + b - 1) / b);
        cur -= k * b;
    }

    if (cur < 0) {
        printf("No\n");
        return;
    }

    if (d == b) {
        printf("Yes\n");
        return;
    }

    // Now we have d > b

    if (b <= c + 1) {
        printf("Yes\n");
        return;
    }

    // Now we have b > c + 1

    ll g = __gcd(b, d);
    ll L = cur - (b - 1), R = cur - (c + 1);
    ll tmp = max(0ll, (-R + g - 1) / g);

    R += tmp * g;
    L += tmp * g;
    R = (R / g) * g;
    L -= tmp * g;
    R -= tmp * g;

    if (R >= L) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
    }
}

int main() {
    int tt;
    scanf("%d", &tt);

    while (tt--) {
        solve();
    }

    return 0;
}