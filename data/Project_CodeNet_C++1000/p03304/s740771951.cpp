#include <bits/stdc++.h>

using namespace std;

int n, m, d;

int main() {
    scanf("%d %d %d", &n, &m, &d);
    if(d == 0) printf("%f\n", 1.0 * (m - 1) / n);
    else printf("%f\n", 2.0 * (m-1) * (n - d) / n / n);

    return 0;
}