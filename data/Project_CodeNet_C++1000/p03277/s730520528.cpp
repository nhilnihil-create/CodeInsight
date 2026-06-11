#include <cstdio>
#include <cstring>

typedef long long ll;

ll ms(int a[], int l, int r) {
    if (l == r) {
        return 0;
    }

    ll ret = 0;
    int mi = (l + r) / 2;
    ret += ms(a, l, mi);
    ret += ms(a, mi + 1, r);

    int t[r-l+1];
    int i1 = l, i2 = mi + 1;
    for (int i = 0; i < r - l + 1; i++) {
        if (i2 == r + 1 || i1 <= mi && a[i1] <= a[i2]) {
            t[i] = a[i1++];
            ret += r + 1 - i2;
        } else {
            t[i] = a[i2++];
        }
    }

    memcpy(a + l, t, sizeof(t));
    
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int l = 0, r = 1e9+1;
    while (r - l > 1) {
        int m = (l + r) / 2;

        int b[n+1];
        b[0] = 0;
        for (int i = 1; i <= n; i++) {
            b[i] = (a[i-1] >= m ? 1 : -1) + b[i-1];
        }
        
        if (ms(b, 0, n) * 2 >= 1ll * (n + 1) * n / 2) {
            l = m;
        } else {
            r = m;
        }
    }

    printf("%d\n", l);

    return 0;
}