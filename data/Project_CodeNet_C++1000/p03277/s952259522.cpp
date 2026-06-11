#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
int a[100001];
int b[100001];

int seg[600000];

void update(int i) {
    i += 200000;
    while (i < 600000) {
        ++seg[i];
        i += i & -i;
    }
}

int query(int i) {
    i += 200000;
    int ret = 0;
    while (i) {
        ret += seg[i];
        i -= i & -i;
    }
    return ret;
}

int check() {
    for (int i = 0; i < 600000; ++i) seg[i] = 0;
    for (int i = 2; i <= n; ++i) b[i] += b[i - 1];
    update(0);
    llong ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += query((b[i] << 1) - i);
        update((b[i] << 1) - i);
    }
    return (n + 1ll) * n <= (ret << 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int s = 1, e = 1e9;
	while (s < e) {
        int m = (s + e + 1) / 2;
        for (int i = 1; i <= n; ++i) b[i] = (m <= a[i]);
        if (check()) s = m;
        else e = m - 1;
	}
	printf("%d\n", s);
	return 0;
}
