#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n;
ll a[N], b[N], r;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", a + i);
        b[n + 1 - i] = a[i];
    }
    partial_sum(a + 1, a + n + 1, a + 1);
    partial_sum(b + 1, b + n + 1, b + 1);
    r = a[n];
    for(int i = 2; i <= n - 2; i++){
        int x = int(lower_bound(a + 1, a + i + 1, (a[i] + 1) / 2) - a);
        int y = int(lower_bound(b + 1, b + (n - i) + 1,
            (b[n - i] + 1) / 2) - b);
        for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++){
            auto t = minmax({a[x - j], a[i] - a[x - j],
                b[y - k], b[n - i] - b[y - k]});
            r = min(r, t.second - t.first);
        }
    }
    printf("%lld\n", r);
}