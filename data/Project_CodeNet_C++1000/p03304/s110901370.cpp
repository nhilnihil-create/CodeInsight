#include <bits/stdc++.h>
using namespace std;
int main () {
    long long n, m, d;
    cin >> n >> m >> d;
    long long k;
    if (n-1 < d+d || d == 0) {
        k = 0;
    }
    else {
        k = n-d-d;
    }
    long double a = (n+k)*(m-1);
    a /= n*n;
    printf("%.10Lf\n", a);
}