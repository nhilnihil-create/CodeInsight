#include<bits/stdc++.h>
using namespace std;
#define N 384

int n;
double memo[N][N][N];

double e(int ones, int twos, int threes) {
    if ((ones | twos | threes) == 0) return 0.0;

    double &m = memo[ones][twos][threes];
    if (m != 0.0) return m;

    double mult = 1.0 * n / (ones + twos + threes);
    double sum = 0;
    sum += ones == 0 ? 0 : 1.0 * ones / n * e(ones - 1, twos, threes);
    sum += twos == 0 ? 0 : 1.0 * twos / n * e(ones + 1, twos - 1, threes);
    sum += threes == 0 ? 0 : 1.0 * threes / n * e(ones, twos + 1, threes - 1);
    return m = mult * (1 + sum);
}

int main() {
    scanf("%d", &n);
    int cnt[3 + 1]; memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
        int v; scanf("%d", &v);
        cnt[v]++;
    }
    printf("%.12lf\n", e(cnt[1], cnt[2], cnt[3]));
}

