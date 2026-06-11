#include <algorithm>
#include <cstdio>
#include <map>
#define N 200005
using namespace std;
typedef long long ll;

int n, a[N];

inline bool check(ll x) {
    map<ll, ll> num;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) continue;
        while (!num.empty() && num.rbegin()->first >= a[i]) {
            num.erase(--num.end());
        }
        for (int j = a[i] - 1; j >= 0; --j) {
            ++num[j];
            if (num[j] == x) num.erase(j);
            else break;
            if (j == 0) return 0;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
      bool flag = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
          flag = false;
          break;
        }
    }
    if (flag) {
        puts("1");
        return 0;
    }
    ll l = 2, r = n + 1, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = (ans = mid) - 1;
        else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
