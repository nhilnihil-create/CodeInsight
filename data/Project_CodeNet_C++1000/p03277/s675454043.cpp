#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int MAXVAL = (int) 1e5 + 5;

int aib[2 * MAXVAL + 1][2], n;

inline void update(int pos, int val, int r) {
    pos += n + 1;
    for(int i = pos; i <= 2 * MAXVAL; i += lsb(i)) {
        aib[i][r] += val;
    }
}

inline int query(int pos, int r) {
    int ans = 0;
    pos += n + 1;
    for(int i = pos; i > 0; i -= lsb(i)) {
        ans += aib[i][r];
    }
    return ans;
}

int arr[MAXN + 1];

inline ll check(int val) {
    memset(aib, 0, sizeof(aib));
    ll ans = 0;
    int cnt = 0;
    update(1, 1, 0);
    for(int i = 1; i <= n; i++) {
        cnt += (arr[i] <= val);
        ans += query(cnt - i / 2, i & 1) + query(cnt - (i - 1) / 2, 1 - i & 1);
        update(cnt - i / 2 + 1, 1, i & 1);
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll nr = 1LL * n * (n + 1) / 2;
    int res = 0;
    for(int step = 1 << 29; step; step >>= 1) {
        if(check(res + step) < nr / 2 + 1) {
            res += step;
        }
    }
    cout << res + 1;
    //cin.close();
    //cout.close();
    return 0;
}
