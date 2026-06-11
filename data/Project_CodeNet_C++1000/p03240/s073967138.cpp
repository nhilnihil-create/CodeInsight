#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a, b, u, x[101], y[101], h[101], cx, cy, H;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] != 0) u=i;
    } 

    for (int xi = 0; xi <= 100; xi++) {
        for (int yi = 0; yi <= 100; yi++) {
            cx = xi, cy = yi;
            H = h[u] + abs(x[u]-cx) + abs(y[u]-cy);

            for (int i = 1; i <= n; i++) {
                if (h[i] != max(H-abs(cx-x[i])-abs(cy-y[i]), 0)) break;
                if (i == n) {
                    printf("%d %d %d\n", cx, cy, H);
                    return 0;
                }
            }
        }
    }
}
