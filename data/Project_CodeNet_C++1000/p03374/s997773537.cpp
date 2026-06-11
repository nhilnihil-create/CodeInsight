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
    ll n,c;
    cin >> n >> c;
    vector<pll> sushi(n);
    rep(i,n){
        ll x, v;
        cin >> x >> v;
        sushi[i] = mp(x, v);
    }
    vll migione(n + 1, 0), migitwo(n + 1, 0), hidarione(n + 1, 0), hidaritwo(n + 1, 0);
    ll now = 0;
    rep(i,n){
        now += sushi[i].S;
        migione[i + 1] = max(now - sushi[i].F, migione[i]);
        migitwo[i + 1] = max(now - 2 * sushi[i].F, migitwo[i]);
    }
    now = 0;
    repr(i,n-1,-1){
        now += sushi[i].S;
        hidarione[i] = max(now - c + sushi[i].F, hidarione[i + 1]);
        hidaritwo[i] = max(now -2*( c - sushi[i].F), hidaritwo[i + 1]);
    }

    ll ans = max(migione[n], hidarione[n]);
    
    rep(i,n+1){
        ans = max(ans, max(migitwo[i] + hidarione[i], migione[i] + hidaritwo[i]));
    }
    /*
    rep(i,n+1){
        cout << migione[i] << " ";
    }
    cout << endl;
    rep(i, n + 1)
    {
        cout << migitwo[i] << " ";
    }
    cout << endl;
    rep(i, n + 1)
    {
        cout << hidarione[i] << " ";
    }
    cout << endl;
    rep(i, n + 1)
    {
        cout << hidaritwo[i] << " ";
    }
 
    cout << endl;    */

    cout << ans << endl;
}