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

struct COMB
{
    int L;
    vll kaijo, gyaku;
    void __init__(int sz)
    {
        L = sz;
        kaijo.resize(L + 1, 0);
        gyaku.resize(L + 1, 0);
        kaijo[0] = 1;
        repf(i, 1, L + 1)
            kaijo[i] = (kaijo[i - 1] * i) % mod;
        gyaku[L] = powmod(kaijo[L], mod - 2, mod);
        rep(i, L)
            gyaku[L - 1 - i] = gyaku[L - i] * (L - i) % mod;
    }
    ll powmod(ll x, ll y, ll mod)
    {
        if (y==0)
            return 1;
        map<ll, ll> Z;
        Z[0] = 1;
        Z[1] = x;
        ll nowy = 1;
        ll nowx = x;
        while (nowy * 2 <= y)
        {
            nowy *= 2;
            nowx = nowx * nowx % mod;
            Z[nowy] = nowx;
        }
        ll nowz = nowy / 2;
        while (nowy < y)
        {
            if (nowz + nowy <= y)
            {
                nowy += nowz;
                nowx = (nowx * Z[nowz]) % mod;
            }
            nowz /= 2;
        }
        return nowx;
    }

    ll calc_comb(int n, int k)
    {
        if (n > L)
            return -1;
        return (((kaijo[n] * gyaku[k]) % mod) * gyaku[n - k]) % mod;
    }
    ll calc_kaijo(int i)
    {
        return kaijo[i];
    }
    ll calc_gyaku(int i)
    {
        return gyaku[i];
    }
};

int main()
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    COMB comb;
    comb.__init__(n);
    vll bunsu(n + 1, 0);
    repf(i,1,n+1){
        bunsu[i] = comb.powmod(i, mod - 2, mod);
    }
    vll s(n + 1, 0);
    rep(i,n){
        s[i+1]=(s[i]+bunsu[i+1])%mod;
    }
    ll ans = 0;
    rep(i,n){
        ll now = (mod + s[n - i] + s[i + 1] - s[1]) % mod;
        now = (now * comb.calc_kaijo(n)) % mod;
        now = (a[i] * now) % mod;
        ans = (ans + now) % mod;
    }
    cout << ans << endl;
}
