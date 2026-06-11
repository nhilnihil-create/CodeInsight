#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 100005;

int v[NMAX], sorted[NMAX], s[NMAX], n;
ll aint[8 * NMAX];

void update(int toadd, int pos, int node, int le, int ri) {
    if(le == ri)
        aint[node] += toadd;
    else {
        int mid = (le + ri) / 2;
        if(pos <= mid)
            update(toadd, pos, node * 2, le, mid);
        else
            update(toadd, pos, node * 2 + 1, mid + 1, ri);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
}

ll query(int from, int to, int node, int le, int ri) {
    if(from <= le && ri <= to)
        return aint[node];
    int mid = (le + ri) / 2;
    ll ans = 0;
    if(from <= mid)
        ans += query(from, to, node * 2, le, mid);
    if(mid < to)
        ans += query(from, to, node * 2 + 1, mid + 1, ri);
    return ans;
}

ll check(int val) {
    for(int i = 1; i <= n; i ++) {
        if(v[i] <= val)
            s[i] = -1;
        else
            s[i] = 1;
        s[i] += s[i - 1];
    }
    ll ans = 0;

    for(int i = 1; i <= n; i ++) {
        update(1, s[i] + n, 1, 0, 2 * n);
        ans += query(s[i] + n + 1, 2 * n, 1, 0,  2 * n);
        if(s[i] < 0)
            ans ++;
    }
    for(int i = 1; i <= n; i ++)
        update(-1, s[i] + n, 1, 0, 2 * n);

    return ans;
}

int main() {
   // freopen("a.in", "r", stdin);
 //  freopen("a.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        sorted[i] = v[i];
    }
    sort(sorted + 1, sorted + n + 1);
    int ans = 0;
    ll m = 1LL * n * (n + 1) / 2;
    for(int step = (1 << 17); step; step >>= 1)
        if(ans + step <=  n && check(sorted[ans + step]) < (m / 2 + 1))
            ans += step;
    cout << sorted[ans + 1];

    return 0;
}
