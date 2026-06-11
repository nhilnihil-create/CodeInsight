// That was so silly...
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll; 

const int Maxv = 200010; 

ll sum[Maxv], ans = 1ll << 60, res; 
int n, m; 

int main() {
    scanf("%d%d", &n, &m); 

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]); 
        sum[i] += sum[i - 1]; 
    }

    for (int i = 1; i <= n; i++) {
        res = 1ll * (i + n) * m; 

        for (int j = n, tmp = 0; j > 0; j -= i, tmp++) {
            ll val = (tmp ? (tmp << 1) + 3 : 5) * (sum[j] - sum[std::max(j - i, 0)]); 
            res += val;

            if (res >= ans) break; 
        }

        ans = std::min(ans, res); 
    }

    printf("%lld\n", ans); 

    return 0; 
}