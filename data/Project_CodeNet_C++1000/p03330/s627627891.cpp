#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define rnfor(i,a,b) for(ll (i) = (a) - 1; (i) >= (b); --(i))
#define ll long long
#define mod (1000000007)
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()
const ll inf = 1e9;

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll t = 1;
    rep1(i, n)t *= i;
    return t;
}

ll combinations(ll n, ll k) {
    ll r = 1;
    rep1(i, k)r = r * n-- / i;
    return r;
}

int main(){
    ll n,c;
    cin >> n >> c;
    ll d[c][c],g[n][n],cnt[3][c];
    rep0(i, 3)rep0(j, c)cnt[i][j] = 0;
    rep0(i, c)rep0(j, c)cin >> d[i][j];
    rep0(i, n)rep0(j, n){
        cin >> g[i][j];
        --g[i][j];
        ++cnt[(i + j + 2) % 3][g[i][j]];
    }
    ll ans = inf;
    rep0(i, c)rep0(j, c){
        if(i == j)continue;
        rep0(k, c){
            if(j == k || i == k)continue;
            ll cnt1 = 0;
            rep0(l, c)cnt1 += d[l][i] * cnt[0][l];
            rep0(l, c)cnt1 += d[l][j] * cnt[1][l];
            rep0(l, c)cnt1 += d[l][k] * cnt[2][l];
            ans = min(ans,cnt1);
        }
    }
    pf(ans);
    return 0;
}
