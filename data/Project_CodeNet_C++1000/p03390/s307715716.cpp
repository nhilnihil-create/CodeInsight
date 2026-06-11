#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q;
ll a, b;

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%lld %lld", &a, &b);
        if (a == b) {
            printf("%lld\n", 2 * (a - 1));
        } else {
            ll t = sqrt(a * b);
            if (t * t == a * b) t--;
            if (t * (t + 1) < a * b) printf("%lld\n", 2 * t - 1);
            else printf("%lld\n", 2 * (t - 1));
        }
    }
    return 0;
}