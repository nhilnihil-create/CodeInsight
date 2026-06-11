#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int mod = 998244353;
const int MAXN = (int)3e5 + 5;

int fact[MAXN];

int rev[MAXN];

ll a, b, k;

int n, ans;

int binPow(int a, int b, int m = mod) {
    int ret = 1;

    while (b > 0) {
        if (b & 1) {
            ret = (ret * 1ll * a) % m;
        }

        a = (a * 1ll * a) % m;
        b >>= 1;
    }

    return ret;
}

void pre() {
    fact[0] = rev[0] = 1;

    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * 1ll * i) % mod;
        rev[i] = binPow(fact[i], mod - 2);
    }
}

void addMod(int &a, int b, int m = mod) {
    a += b;

    if (m <= a) {
        a -= m;
    }
}

int C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    return fact[n] * 1ll * rev[k] % mod * rev[n - k] % mod;
}


int main() {
    pre();

		scanf("%d %lld %lld %lld", &n, &a, &b, &k);

    for (int x = 0; x <= n; ++x) {
        ll left = k - x * a;

        if (left < 0) {
            break;
        }

        if (left % b == 0 && left / b <= n) {
            int y = left / b;
            addMod(ans, C(n, x) * 1ll * C(n, y) % mod);
        }
    }

    printf("%d\n", ans);



    return 0;
}