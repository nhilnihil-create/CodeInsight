#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int queryCount;
    scanf("%d", &queryCount);

    for (int i = 0; i < queryCount; ++i) {
        long long res = 0;
        long long first, second;

        scanf("%lld%lld", &first, &second);

        long long x = (long long)sqrt(first * second - 1);

        while (x * x >= first * second) x--;

        res = x * 2;

        if (first <= x) res--;
        if (second <= x) res--;

        if ((x + 1) * x >= (first * second)) {
            res--;
        }

        printf("%lld\n", res);
    }

    return 0;
}
