#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
using namespace std;

// 插入此處

LL a[100005];

LL prefix[100005];

int main() {
    LL n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    prefix[0] = a[0] % m;
    for (int i = 1; i < n; i++) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }
    sort(prefix, prefix + n);

    vector<LL> group;

    LL count = 1;
    for (int i = 1; i < n; i++) {
        if (prefix[i] != prefix[i-1]) {
            group.push_back(count);
            count = 1;
        } else {
            count++;
        }
    }
    group.push_back(count);

    LL ans = 0;
    for (auto c : group) {
        ans += (c * (c-1)) / 2;
    }
    for (int i = 0; i < n; i++) {
        if (prefix[i] % m == 0) {
            ans++;
        }
    }
    printf("%lld\n", ans);
}
