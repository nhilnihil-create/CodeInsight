#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mod 1000000007
 
const int mxN = 2e5 + 1;
ll n;
ll h[mxN], b[mxN], dp[mxN] = {};
ll seg[4*mxN] = {};

void upd(ll seg[], ll i, ll val, ll st = 1,ll en = n, ll ind = 0)
{
    if(st <= i && i <= en)
        seg[ind] = max(seg[ind], val);
    if(i < st || i > en || st == en)
        return;
    ll mid = (st + en) / 2;
    upd(seg, i, val, st, mid, 2*ind+1);
    upd(seg, i, val, mid+1, en, 2*ind+2);
}

ll qry(ll seg[], ll qs, ll qe, ll st = 1, ll en = n, ll ind = 0)
{
    if(qe < st || en < qs)
        return -1e18;
    if(qs <= st && en <= qe)
        return seg[ind];
    ll mid = (st + en) / 2;
    return max(qry(seg, qs, qe, st, mid, 2*ind+1), qry(seg, qs, qe, mid+1, en, 2*ind+2));
}
 
int main()
{
FIO
 
    cin >> n;
    For(n) cin >> h[i];
    For(n) cin >> b[i];

    dp[h[0]] = b[0];
    upd(seg, h[0], dp[h[0]]);
    FOR(n-1)
    {
        ll temp = h[i] == 1 ? 0: qry(seg, 1, h[i]-1);
        dp[h[i]] = b[i] + temp;
        upd(seg, h[i], dp[h[i]]);
    }

    cout << *max_element(dp + 1, dp + n + 1);
}