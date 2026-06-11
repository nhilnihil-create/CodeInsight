#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
constexpr int MOD = 1000000007;

int mod(const ll &x){
    return x > 0 ? x % MOD : (x+MOD) % MOD;
}

int modm(const ll &x,const ll &m){
    return (x % MOD) * (m % MOD) % MOD;
}

int modpow(ll x, ll p) {
    int ret = 1;
    while(p > 0) {
        if (p & 1) ret = modm(ret,x);
        x = modm(x,x);
        p >>= 1;
    }
    return ret;
}

// x * modinv(d)
int modd(ll x,ll d) {
    return modm(x,modpow(d,MOD-2));
}

int main(void)
{
    IOS
    const int C = 26;
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(C);
    REP(i,n) a[s[i] - 'a']++;
    ll ans = 1;
    REP(i,C) ans = modm(ans,a[i]+1);
    ans = mod(ans-1);

    cout << ans << '\n';

    return 0;
}