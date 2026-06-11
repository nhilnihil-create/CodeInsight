#include <bits/stdc++.h>

#define N 1010 

using namespace std;

typedef long long ll;

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

ll X[N], Y[N];

int dx[] = {1, 0, -1, 0};

int dy[] = {0, 1, 0, -1};

char output[] = {'L', 'D', 'R', 'U'};

int main() {
    int n = rd();
    X[1] = rd(), Y[1] = rd();
    bool pre = (X[1] + Y[1]) & 1;
    for (int i = 2; i <= n; i ++ ) {
        X[i] = rd(), Y[i] = rd();
        if (((X[i] + Y[i]) % 2 != 0) != pre) {
            puts("-1");
            return 0;
        }
    }

    if (!pre) {
        for (int i = 1; i <= n; i ++ ) {
            X[i] -- ;
        }
    }

    if (pre) {
        puts("31");
    }
    else {
        puts("32");
    }
    if (!pre) {
        printf("1 ");
    }
    ll tmp = 1;
    printf("1 ");
    for (int i = 1; i <= 30; i ++ ) {
        tmp <<= 1;
        printf("%lld ", tmp);
    }
    puts("");
    for (int i = 1; i <= n; i ++ ) {
        string ans = "";
        int x = X[i], y = Y[i];
        for (int j = 30; ~j; j -- ) {
            ll mdl = (1ll << j);
            for (int k = 0; k < 4; k ++ ) {
                ll x_ = x + mdl * dx[k], y_ = y + mdl * dy[k];
                if (abs(x_) + abs(y_) <= mdl - 1) {
                    x = x_, y = y_;
                    ans.push_back(output[k]);
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (!pre) {
            putchar('R');
        }
        cout << ans << endl ;
    }
    return 0;
}