#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define N 200200
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

int n, a[N], top;
pii stk[N];

inline bool check(int mid) {
    stk[0] = make_pair(0, 0);
    stk[top = 1] = make_pair(1, a[1]);
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            while (top && stk[top].fi == 1) 
                --top;
            stk[++top] = make_pair(1, a[i]);
        } else {
            int now = 0;
            while (top && stk[top].se >= a[i])
                now = stk[top--].fi;
            if (now < mid) {
                if (stk[top].se != a[i] - 1)
                    stk[++top] = make_pair(now, a[i] - 1);
                else while (top && stk[top].fi == now + 1) --top;
                stk[++top] = make_pair(now + 1, a[i]);
            } else {
                if (!top) return false;
                now = stk[top].fi;
                int pos = stk[top].se;
                if (stk[top - 1].se == pos - 1) {
                    if (top) for (--top; top && stk[top].fi == now + 1; --top);
                    stk[++top] = make_pair(now + 1, pos);
                } else stk[top].se--, stk[++top] = make_pair(now + 1, pos);
                stk[++top] = make_pair(1, a[i]);
            }
        }
    }
    return true;
}

int main() {
#ifdef isLOCAL
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;
    bool chk = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] <= a[i - 1]) chk = false;
    }
    if (chk) return puts("1"), 0;

    int l = 2, r = n - 1, res = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = (res = mid) - 1;
        else l = mid + 1;
    }

    cout << res << endl;

    return 0;
}
