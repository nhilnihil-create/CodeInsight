#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define task "LUCKYSQ"
#define pll pair<ll, ll>
#define pii pair<ll, pll>
#define fi first
#define se second
using namespace std;
const ll mod = 998244353;
const ll N = 2e5 + 5;
const ll mxn = 1e6 + 5;

ll n, m, u, v, st[N*4], t, k, T, ans, tong, a[N], b[N], d[N];
vector<ll> kq;
void build(ll id, ll l , ll r)
{
    if(l > u || u > r)return;
    if(l == r)
    {
        st[id] += 1;
        return;
    }
    ll mid = (l + r) / 2;
    if(mid >= u)build(id*2, l, mid);
    else build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}
ll get(ll id, ll l, ll r)
{
    if(u > r || l > v)return 0;
    if(u <= l && r <= v)return st[id];
    ll mid = (l + r) / 2;
    return get(id*2, l ,mid) + get(id*2+1, mid+1, r);
}
ll f(ll u)
{
    return lower_bound(kq.begin(), kq.end(), u) - kq.begin() + 1;
}
bool ck(ll x)
{
    kq.clear();
    memset(st, 0, sizeof(st));
    tong = 0;
    for(int i = 1; i <= n; i ++)
    {
        d[i] = d[i-1];
        if(a[i] >= x) ++ d[i];
        kq.pb(2*d[i] - i);
    }
    kq.pb(0);
    sort(kq.begin(), kq.end());
    kq.erase(unique(kq.begin(), kq.end()), kq.end());
    u = f(0);
    build(1, 1, n+1);
    for(int i = 1; i <= n; i ++)
    {
        u = 1, v = f(2*d[i]-i);
        tong += get(1, 1, n+1);
        u = f(2*d[i]-i);
        build(1, 1, n+1);
    }
    //cout << x <<" "<<tong<<endl;
    return tong >= ans;
}
inline void sol()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+1+n);
    ll lf = 1, rt = n, mid;
    ans = n * (n + 1) / 2;
    ans = (ans + 1) / 2;
    while(lf <= rt)
    {
        mid = (lf + rt) / 2;
        if(ck(b[mid]))lf = mid + 1;
        else rt = mid - 1;
    }
    cout << b[rt];
}
int main()
{
    if(fopen(task".INP", "r")){
       freopen(task".INP", "r", stdin);
       freopen(task".OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
}




