#include <iostream>

using namespace std;

const int DIM = 200010;

int n, q, i, p, u, m, st, dr, aux, b[DIM];
char s[DIM], a[DIM], c;

int calculeaza(int x) {
    for (i = 1; i <= q; ++i) {
        if (s[x] == a[i]) {
            x += b[i];
        }
        if (x == 0 || x == n + 1) {
            break;
        }
    }
    return x;
}

int main() {
    cin >> n >> q;
    cin >> s + 1;
    for (i = 1; i <= q; ++i) {
        cin >> a[i] >> c;
        if (c == 'L') {
            b[i] = -1;
        } else {
            b[i] = 1;
        }
    }

    p = 1;
    u = n;
    while (p <= u) {
        m = (p + u) >> 1;
        aux = calculeaza(m);
        if (aux == 0) {
            st = m;
            p = m + 1;
        } else {
            u = m - 1;
        }
    }

    p = 1;
    u = n;
    dr = n + 1;
    while (p <= u) {
        m = (p + u) >> 1;
        aux = calculeaza(m);
        if (aux == n + 1) {
            dr = m;
            u = m - 1;
        } else {
            p = m + 1;
        }
    }

    cout << dr - st - 1 << "\n";

	return 0;
}
