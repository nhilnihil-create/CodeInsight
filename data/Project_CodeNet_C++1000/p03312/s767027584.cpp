#include <bits/stdc++.h>

using namespace std;

const int maxn=200005;

typedef long long ll;

ll sum[maxn],a[maxn];

ll n,b,c,d,e;

ll ans=1e15+7;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0, f = 1;
	char c = nc();
	while (c < 48) {
		if (c == '-')
			f = -1;
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x * f;
}

bool check(ll x, ll y, int i) {
    if (abs((x + a[i]) - (y - a[i])) < abs(x - y)) {
    	return true;
	}
	return false;
}

int main() {
	n = rd();
    ll s = 0;
    for (int i = 0; i < n; i ++ ) {
		a[i] = rd();
        s += a[i];
        sum[i] = s;
    }
    int j = 0, k = 2;
    for (int i = 1; i < n - 2; i ++ ) {
        b = sum[j];
        c = sum[i] - sum[j];
        d = sum[k] - sum[i];
        e = sum[n - 1] - sum[k];
        while (check(b, c, j + 1) && j + 1 < i) {
            j ++ ;
            b = sum[j];
            c = sum[i] - sum[j];
        }
        while (check(d, e, k + 1) && k + 1 < n - 1)
        {
            k ++ ;
            d = sum[k] - sum[i];
            e = sum[n - 1] - sum[k];
        }
        ll test[10];
        test[0] = b;
		test[1] = c;
        test[2] = d;
		test[3] = e;
        sort(test, test + 3 + 1);
        ans = min(ans, test[3] - test[0]);
    }
	cout << ans << endl ;
    return 0;
}