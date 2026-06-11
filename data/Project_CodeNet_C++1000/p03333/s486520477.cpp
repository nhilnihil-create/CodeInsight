#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int n;
int L[N], R[N];
multiset <pair <int, int> > st, ed;
ll solve() {
    for (int i = 0; i < n; ++ i) {
        st.insert(make_pair(L[i], i));
        ed.insert(make_pair(R[i], i));
    }
    multiset <pair <int, int> > :: iterator it;
    int p = 0;
    int tp = 1;
    ll ans = 0;
    int cnt = 0;
    ll mx = 0;
    while (!st.empty()) {
        mx = max(mx, ans + abs(p));
        if (cnt == 5) break;
        tp ^= 1;
        if (tp & 1) {
            it = ed.begin();
            if (p > it -> first) {
                ans += p - it -> first;
                p = it -> first;
            }
            else {
                ++ cnt;
                continue;
            }
            st.erase(st.find(make_pair(L[it -> second], it -> second)));
            ed.erase(it);
        }
        else {
            it = -- st.end();
            if (p < it -> first) {
                ans += it -> first - p;
                p = it -> first;
            }
            else {
                ++ cnt;
                continue;
            }
            ed.erase(ed.find(make_pair(R[it -> second], it -> second)));
            st.erase(it);
        }
    }
    return max(mx, ans + abs(p));
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", L + i, R + i);
    }
    L[n] = 0, R[n] = 0, ++ n;
    sort(L, L + n); sort(R, R + n);
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; ++ i) {
        cur += L[n - i - 1] - R[i];
        ans = max(ans, cur);
    }
    printf("%lld\n", ans * 2);
    // printf("%lld\n", solve());
    return 0;
}
