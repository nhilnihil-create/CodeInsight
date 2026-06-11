#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head
const int nax = 2e5+2;
vector<ll> t(4*nax);

void update(int v, int tl, int tr, int p, ll val) {
    if(tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if(p <= tm)
            update(2*v, tl, tm, p, val);
        else update(2*v+1, tm + 1, tr, p, val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
ll maxi(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return max(maxi(v*2, tl, tm, l, min(r, tm)), maxi(v*2+1, tm + 1, tr, max(l, tm + 1), r));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi h(n);
    vll a(n);
    rep(i,0,n) cin >> h[i];
    rep(i,0,n) cin >> a[i];

    vll dp(n + 1);
    rep(i,0,n) {
        // find the max value of dp[i] from [0, h[i] - 1]
        ll val = maxi(1,0,n,0,h[i]-1);
        //ll val = maxi(1,0,n,0,h[i]-1);
        if(val + a[i] > dp[h[i]]) {
            dp[h[i]] = val + a[i];
            update(1,0,n,h[i],val + a[i]);
        }
        //dp[h[i]] = max(val + a[i], dp[h[i]]);
        //dp[h[i]] = val + a[i];
        /*rep(j,0,h[i]) {
            dp[h[i]] = max(dp[h[i]], dp[j] + a[i]);
        }*/
    }
    cout << t[1] << endl;
    return 0;
}
