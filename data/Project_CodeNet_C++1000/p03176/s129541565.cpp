#include <bits/stdc++.h>

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif

//{{{
using namespace std;
typedef long long LL;
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
// clang-format off
#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr<<endl;}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while
(getline(ss, x, c)) v.push_back(x); return v;} void err(vector<string>::iterator) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}
// clang-format on
//}}}

const int N = 2e5 + 10;
int T;

int n;
LL dp[N];
LL a[N], h[N];
vector<pair<int, pair<int, LL>>> arr;

#define L(x) x << 1
#define R(x) x << 1 | 1

struct st
{
    int l, r;
    LL lazy, maxi;
} seg[N << 2];

void pushup(int rt)
{
    //
    seg[rt].maxi = max(seg[L(rt)].maxi, seg[R(rt)].maxi);
}

void pushdown(int rt)
{
    if (seg[rt].lazy)
    {
        seg[rt].lazy = 0;
    }
}

void build(int l, int r, int rt = 1)
{
    if (rt == 1) r++;
    seg[rt].l = l, seg[rt].r = r;
    seg[rt].lazy = 0;

    if (l + 1 == r)
    {
        seg[rt].maxi = 0;
        return;
    }

    int mid = (l + r) >> 1;
    build(l, mid, L(rt));
    build(mid, r, R(rt));

    pushup(rt);
}

void modify(int l, int r, LL val, int rt = 1)
{
    if (rt == 1) r++;
    if (l <= seg[rt].l && seg[rt].r <= r)
    {
        seg[rt].maxi = val;
        return;
    }

    pushdown(rt);

    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (l < mid) modify(l, r, val, L(rt));
    if (r > mid) modify(l, r, val, R(rt));

    pushup(rt);
}

LL query(int l, int r, int rt = 1)
{
    if (rt == 1) r++;
    if (l <= seg[rt].l && seg[rt].r <= r) return seg[rt].maxi;

    pushdown(rt);

    int mid = (seg[rt].l + seg[rt].r) >> 1;
    LL maxi = 0;
    if (l < mid) maxi = max(maxi, query(l, r, L(rt)));
    if (r > mid) maxi = max(maxi, query(l, r, R(rt)));

    return maxi;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i <= n; i++) cin >> a[i];
        arr.clear();
        for (int i = 1; i <= n; i++)
        {
            arr.push_back({h[i], {i, a[i]}});
        }
        sort(arr.begin(), arr.end());

        LL ans = 0;
        build(1, n);
        for (int i = 0; i < n; i++)
        {
            // int curh = arr[i].first;
            int pos = arr[i].second.first;
            LL val = arr[i].second.second;

            LL dpv = 0;

            // query
            if (pos == 1)
            {
                dpv = val;
            }
            else
            {
                LL v = query(1, pos - 1);
                dpv = v + val;
            }
            // debug(i, curh, pos, val, dpv);
            ans = max(ans, dpv);

            // update
            modify(pos, pos, dpv);
        }
        cout << ans << endl;
    }

    return 0;
}
