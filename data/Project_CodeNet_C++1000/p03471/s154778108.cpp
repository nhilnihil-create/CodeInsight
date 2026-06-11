#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y; scanf("%d%d", &n, &y);
    int y10000=-1, y5000=-1, y1000=-1;

    int t;
    for (int i = 0; i<= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            t = (y - 10000*i - 5000*j)/1000;
            if (t==n-i-j) {y10000=i; y5000=j; y1000=t;}
            if (y1000>0) break;
        }
        if (y1000>0) break;
    }

    printf("%d %d %d\n", y10000, y5000, y1000);
    return 0;
}