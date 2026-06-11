#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

int main() {
    long long n,X; scanf("%lld %lld", &n, &X);
    vector<long long> x(n+1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i+1]);
        x[i+1] += x[i];
    }
    long long ans = INF;
    for (int k = 1; k <= n; k++) {
        long long have = n, cand = 0;
        for (int cost = 3; have > 0; cost += 2) {
            int real_cost = max(5,cost);
            auto paint = have;
            if (paint > k) paint = k;
            cand += (x[have] - x[have-paint]) * real_cost;
            if (cand > INF) cand = INF;
            have -= paint;
        }
        ans = min(ans, cand + X*k);
    }
    printf("%lld\n", ans + X*n);

    return 0;
}
