#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e9 + 7;

int n;
int h[maxN], a[maxN], f[maxN], st[maxN * 4];

void update(int id, int l, int r, int i, int val){
    if(i < l || i > r)
        return;
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v){
    if(v < l || u > r)
        return -inf;
    if(u <= l && v >= r)
        return st[id];
    int mid = (l + r) / 2;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        f[h[i]] = a[i];

    for(int i = 1; i <= n; ++i){
        int mx = get(1, 1, n, 1, h[i]);
        f[h[i]] = max(f[h[i]], mx + a[i]);
        update(1, 1, n, h[i], f[h[i]]);
    }

    int res = 0;
    for(int i = 1; i <= n; ++i)
        res = max(res, f[i]);
    cout << res;
}
