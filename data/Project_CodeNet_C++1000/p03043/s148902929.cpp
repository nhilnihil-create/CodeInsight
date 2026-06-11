#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    scanf("%d %d", &n, &k);
    ld res = 0;
    for (int i = 1; i <= n; i++) {
        ld temp = 1.0 / n;
        for (int j = i; j < k; j *= 2) {
            temp *= 0.5;
        }
        res += temp;
    }
    printf("%.12Lf", res);
    return 0;
}
