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
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
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


int main()
{
    int n;
    cin >> n;
    ll c;
    cin >> c;
    vector<pll> tokei(n);
    vector<pll> hanto(n);
    rep(i,n){
        ll x, v;
        cin >> x >> v;
        tokei[i] = mp(x, v);
        hanto[n - 1 - i] = mp(c - x, v);
    }
    ll nowto = 0;
    ll nowha = 0;
    vll right1(n+1,0);
    vll right2(n+1, 0);
    vll left1(n+1, 0);
    vll left2(n+1, 0);
    rep(i,n){
        nowto += tokei[i].S;
        nowha += hanto[i].S;
        //cout << nowto << " " << tokei[i].F << endl;
        //cout << nowha << " " << hanto[i].F << endl;
        right1[i + 1] = nowto - tokei[i].F;
        right2[i + 1] = nowto - 2 * tokei[i].F;
        left1[i + 1] = nowha - hanto[i].F;
        left2[i + 1] = nowha - 2 * hanto[i].F;
    }
    rep(i,n)
    {
        right1[i + 1] = max(right1[i], right1[i + 1]);
        right2[i + 1] = max(right2[i], right2[i + 1]);
        left1[i + 1] = max(left1[i], left1[i + 1]);
        left2[i + 1] = max(left2[i], left2[i + 1]);
    }
    ll ans = 0;
    rep(i,n+1){
        ans = max(ans, max(right1[i] + left2[n - i], right2[i] + left1[n - i]));
    }
    cout << ans << endl;
}