#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    // input 
    int n, m; cin >> n >> m;
    vector<long> x(n,0); vector<long> y(n,0); vector<long> z(n,0);
    vector<long> sum(n,0);
    vector<vector<long>> sum_sum(8,sum);
    bitset<3> bit;
    rep(i, n) {
        scanf("%ld %ld %ld", &x[i], &y[i], &z[i]);
        rep(j, 1<<3) {
            bit = j;
            long xi = x[i], yi = y[i], zi = z[i];
            if (bit.test(0)) {
                xi = -xi;
            }
            if (bit.test(1)) {
                yi = -yi;
            }
            if (bit.test(2)) {
                zi = -zi;
            }
            sum_sum[j][i] += xi + yi + zi;
        }
    }

    long max = 0;
    rep(i, 8) {
        long sum_i = 0;
        sort(sum_sum[i].rbegin(), sum_sum[i].rend());
        rep(j, m) {
            sum_i += sum_sum[i][j];
        }
        // printf("%ld\n", sum_i);
        if (sum_i > max) {
            max = sum_i;
        }
    }
    printf("%ld\n", max);
}