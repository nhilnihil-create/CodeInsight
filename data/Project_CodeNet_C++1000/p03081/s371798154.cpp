// And in the end, the love you take is equal to the love you make.
//                      Paul McCartney (the Beatles). The End. Abbey Road.

#include <bits/stdc++.h>
using namespace std;

char readc() {
    static char inp[4];
    scanf("%s", inp);
    return *inp;
}

const size_t N = 2e5 + 5;

int n, q;
char s[N], t[N], d[N];

int getPos(int p) {
    for (int i = 0; i < q; ++i) {
        if (s[p] == t[i]) {
            p += d[i] == 'L' ? -1 : 1;
        }
    }
    return p;
}

int main() {
    scanf("%d%d%s", &n, &q, s + 1);
    for (int i = 0; i < q; ++i) {
        t[i] = readc();
        d[i] = readc();
    }
    int lb = 0, rb = n + 1;
    /* calc lb */ {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (getPos(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1; lb = mid;
            }
        }
    } /* calc rb */ {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (getPos(mid) <= n) {
                l = mid + 1;
            } else {
                r = mid - 1; rb = mid;
            }
        }
    }
    cout << max(rb - lb - 1, 0) << endl;
    return 0;
}
