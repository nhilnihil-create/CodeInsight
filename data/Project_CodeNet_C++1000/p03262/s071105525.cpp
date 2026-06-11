#include <bits/stdc++.h>
using namespace std;

long gcd(long x, long y) {
   if (x % y == 0) {
       return(y);
   } else {
       return(gcd(y, x%y));
   }
}

int main() {
    int n; long x;
    scanf("%d%ld", &n, &x);
    long cities[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &cities[i]);
    }
    if (n == 1) {
        printf("%ld\n", abs(x-cities[0]));
        return 0;
    }
    long ans = gcd(abs(x-cities[0]), abs(x-cities[1]));
    for (int i = 2; i < n; i++) {
        ans = gcd(ans, abs(x-cities[i]));
    }
    printf("%ld\n", ans);
}