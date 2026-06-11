#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
const int N = 5005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

int n, A, B, p[N];
LL mn[N << 2], tag[N << 2];

inline void pushup(int rt) {
    mn[rt] = min(mn[lc], mn[rc]);
}

inline void puttag(int rt, LL tg) {
    mn[rt] += tg;
    tag[rt] += tg;
}

inline void pushdown(int rt) {
    if (tag[rt]) {
        puttag(lc, tag[rt]);
        puttag(rc, tag[rt]);
        tag[rt] = 0;
    }
}

void SetVal(int rt, int b, int e, int p, LL val) {
    if (b == e) {
        mn[rt] = val;
        return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (p <= mid) SetVal(lc, b, mid, p, val);
    else SetVal(rc, mid + 1, e, p, val);
    pushup(rt);
}

void Update(int rt, int b, int e, int l, int r, LL val) {
    if (l <= b && e <= r) {
        puttag(rt, val);
        return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (l <= mid) Update(lc, b, mid, l, r, val);
    if (r > mid) Update(rc, mid + 1, e, l, r, val);
    pushup(rt);
}

LL Query(int rt, int b, int e, int l, int r) {
    if (l <= b && e <= r) return mn[rt];
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (r <= mid) return Query(lc, b, mid, l, r);
    if (l > mid) return Query(rc, mid + 1, e, l, r);
    return min(Query(lc, b, mid, l, r), Query(rc, mid + 1, e, l, r));
}

void solve() {
    read(n); read(A); read(B);
	for (int i = 1; i <= n; ++i) {
        read(p[i]);
	}
    mset(mn, 0x3f);
    SetVal(1, 0, n, 0, 0);
	for (int i = 1; i <= n; ++i) {
	    LL tmp = Query(1, 0, n, 0, p[i] - 1);
	    SetVal(1, 0, n, p[i], tmp);
        Update(1, 0, n, 0, p[i] - 1, A);
        if (p[i] <n) Update(1, 0, n, p[i] + 1, n, B);
	}
	printf("%lld\n", mn[1]);
}

int main() {
	solve();
	return 0;
}

