#include <bits/stdc++.h>
using namespace std;
struct node {
    map <int, int> s;
    inline void clear(int x) {
        while (s.size() && (--s.end()) -> first >= x) s.erase(--s.end());
    }
    inline int& operator [] (int x) {
        if (!s.count(x)) s[x] = 0;
        return s[x];
    }
} s;
int n, a[200010];
inline int check(int x) {
    s.clear(0);
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) continue;
        s.clear(a[i]);
        int now = a[i] - 1;
        while (now >= 0) {
            if (++s[now] != x) break;
            s[now] = 0;
            now--;
        }
        if (now < 0) return 0;
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int tag = 1;
    for (int i = 2; i <= n; i++) if(a[i] <= a[i - 1]) tag = 0;
    if (tag) return puts("1"), 0;
    int l = 2, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return cout << ans << endl, 0;
}