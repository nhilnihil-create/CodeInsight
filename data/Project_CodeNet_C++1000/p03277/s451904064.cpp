#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl

using namespace std;

const int MN = 100010;

int n;
int a[MN];
int ft[2 * MN];

int h(int x) { return x + MN; }

void update(int pos, int by) {
    while (pos < 2 * MN) ft[pos] += by, pos |= pos + 1;
}

int query(int pos) {
    int res = 0;
    while (pos >= 0) res += ft[pos], pos = (pos & (pos + 1)) - 1;
    return res;
}

int can(int x) {
    long long cnt = 0;
    memset(ft, 0, sizeof ft);
    update(h(0), 1);
    for (int i = 1, sum = 0; i <= n; i++) {
        sum += (a[i - 1] > x ? 1 : -1);
        cnt += i - query(h(sum));
        update(h(sum), 1);
    }
    return cnt >= ((1LL * n * (n + 1)) / 2) / 2 + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n;
	for (int i = 0; i < n; i++)
        cin >> a[i];
    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mi = (hi + lo) / 2;
        if (can(mi)) hi = mi;
        else lo = mi;
    }
    cout << hi << endl;
	return 0;
}
