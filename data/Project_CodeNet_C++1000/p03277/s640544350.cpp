#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

const int maxN = 1e5 + 10;

int n, a[maxN], s[maxN], res;
map < long long, int > mmap;
long long t[maxN];

void update(int x) {
    for (; x <= 1e5; x += (x & (-x)))
        ++t[x];
}

long long get(int x) {
    long long tmp = 0;
    for (; x; x -= (x & (-x)))
        tmp += t[x];
    return tmp;
}


int main() {
    cin >> n;
    int l = 1, r = 1;
    for (int i = 0; i < n; ++i)
        cin >> a[i], r = max(r, a[i]);
    long long req = (1ll * n * (n + 1)) / 2;
    req = (req % 2) ? (req / 2) + 1 : req / 2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        mmap.clear();
        for (int i = 0; i < n; ++i) {
            s[i] = ((i == 0) ? 0 : s[i - 1]) +
                ((a[i] < mid) ? -1 : 1);
            mmap[s[i]] = 0;
        }
        memset(t, 0, sizeof(t));
        int val = 1;
        long long cnt = 0;
        for (auto p : mmap) mmap[p.first] = val++;
        for (int i = 0; i < n; ++i) {
            int v = mmap[s[i]];
            cnt += get(v) + (s[i] >= 0);
            update(v);
        }
        if (cnt >= req) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    cout << res;
}
