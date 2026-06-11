#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int a[N], b[N];
int n;

int c[N];

int lowbit(int x) {return x & (-x);}

void add(int x, int v) {
    for(; x < N; x += lowbit(x)) c[x] += v;
}

int query(int x) {
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += c[x];
    return ans;
}

bool check(int x) {
    b[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] < x) b[i] = -1;
        else b[i] = 1;
        b[i] += b[i - 1];
    }
    int Min = *min_element(b, b + n + 1);
    if(Min <= 0) for(int i = 0; i <= n; i++) b[i] -= Min - 1;
    ll tot = 0;
    for(int i = 0; i <= n; i++) {
        tot += query(b[i]);
        add(b[i], 1);
    }
    for(int i = 0; i <= n; i++) add(b[i], -1);
    return tot >= (1ll * (n + 1) * n / 2 + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e9 + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1;
    return 0;
}
