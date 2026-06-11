#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

struct SegmentTree
{
private:
    int N;
    vector<ll> node;
    ll e;

public:
    SegmentTree() {}
    SegmentTree(ll e) : e(e) {}
    void __init__(int sz)
    {
        N = 1;
        while (N < sz)
            N *= 2;
        node.resize(2 * N - 1, e);
    }
    void build(vector<ll> &v)
    {
        int sz = int(v.size());
        __init__(sz);
        rep(i, sz)
        {
            node[i + N - 1] = v[i];
        }
        for (int i = N - 2; i >= 0; i--)
        {
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }
    void update(int k, ll x)
    {
        k += N - 1;
        node[k] = x;
        while (k > 0)
        {
            k = (k - 1) / 2;
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    void renew(int b, int e, ll x)
    {
        renew(b, e, 0, 0, N, x);
        return;
    }
    void renew(int b, int e, int k, int l, int r, ll x)
    {
        if (e <= 0 || b >= N)
            return;
        if (k > 0)
        {
            node[k] = min(node[k], node[(k - 1) / 2]);
        }
        if (r < b || e < l)
            return;
        if (b <= l && r <= e)
        {
            node[k] = min(node[k], x);
            return;
        }
        else if (k < N - 1)
        {
            renew(b, e, 2 * k + 1, l, (l + r) / 2, x);
            renew(b, e, 2 * k + 2, (l + r) / 2, r, x);
            return;
        }
        return;
    }

    ll get(int i)
    {
        int k = i + N - 1;
        ll res = node[k];
        while (k > 0)
        {
            k = (k - 1) / 2;
            res = min(res, node[k]);
        }
        return res;
    }
    ll query(int a, int b) { return query(a, b, 0, 0, N); }
    ll query(int a, int b, int k, int l, int r)
    {
        if (b <= l || r <= a)
            return e;
        if (a <= l && r <= b)
            return node[k];
        ll vl, vr;
        vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
    void recalc()
    {
        rep(k, N - 1)
        {
            node[2 * k + 1] = min(node[2 * k * 1], node[k]);
            node[2 * k + 2] = min(node[2 * k * 2], node[k]);
        }
    }
    ll show_one(int i)
    {
        return node[i + N - 1];
    }
    void show()
    {
        rep(i, N) cout << node[i] << " ";
        cout << endl;
        return;
    }
};

SegmentTree seg(infl);

int main()
{
    ll n, k, q;
    cin >> n >> k >> q;
    vll a(n);
    rep(i, n) cin >> a[i];
    seg.build(a);
    vll b(n);
    copy(all(a), b.begin());
    sort(all(b));
    ll ans = infl;
    rep(s,n){
        vll value;
        ll res = 0;
        ll idx = 0;
        while (idx+k<=n){
            if (seg.query(idx,idx+k)>=b[s]){
                multiset<ll> now;
                ll cnt = 1;
                repf(i, idx, idx + k) now.insert(a[i]);
                idx += k;
                while (idx<n){
                    if (a[idx]>=b[s]){
                        now.insert(a[idx]);
                        idx++;
                        cnt++;
                    }
                    else{
                        idx++;
                        break;
                    }
                }
                for (auto x = now.begin(); cnt>0;x++){
                    value.pb(*x);
                    cnt--;
                }
            }
            else{
                idx++;
            }
        }
        if (value.size()<q){
            continue;
        }
        else{
            sort(all(value));
            ans = min(ans, value[q-1]-value[0]);
        }
    }
    cout << ans << endl;
}
