#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    int m, k;
    cin >> m >> k;
    int up = (1 << m) - 1;
    if (m == 1 && k == 1) {
        cout << -1 << endl;
    } else if (m == 1 && k == 0) {
        printf("0 0 1 1\n");
    } else if (k <= up) {
        for (int i = 0; i <= up; i++) {
            if (i != k) {
                printf("%d ", i);
            }
        }
        printf("%d ", k);
        for (int i = up; i >= 0; i--) {
            if (i != k) {
                printf("%d ", i);
            }
        }
        printf("%d\n", k);
    } else {
        cout << -1 << endl;
    }
}
