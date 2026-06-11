#include<iostream>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    double m = 1;
    double ans = 0;

    for (int i = n; i > 0; i--) {
        if (i * m >= k) ans += 1 / (m * n);
        else {
            while (i * m < k) m *= 2;
            ans += 1 / (m * n);
        }
    }
  
    printf("%.12f\n", ans);
}