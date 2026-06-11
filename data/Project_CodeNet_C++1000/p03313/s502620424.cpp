#include <bits/stdc++.h>
using namespace std;

int n, fir[1 << 18], sec[1 << 18];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++) {
        scanf("%d", &fir[i]);
    }
    auto upd = [&](int pos, int val) {
        if (val > fir[pos]) sec[pos] = fir[pos], fir[pos] = val;
        else if (val > sec[pos]) sec[pos] = val;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << n; j++) if (!(j >> i & 1)) {
            upd(j | (1 << i), fir[j]), upd(j | (1 << i), sec[j]);
        }
    }
    int lst = 0;
    for (int i = 1; i < 1 << n; i++) {
        lst = max(lst, fir[i] + sec[i]);
        printf("%d\n", lst);
    }
    return 0;
}