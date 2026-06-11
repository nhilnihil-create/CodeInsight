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



int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    map<pair<string, string>, ll> mae;
    map<pair<string, string>, ll> ushiro;
    rep(i,1ll<<n){
        string x, y;
        rep(j,n){
            if ((i>>j)&1){
                x += s[j];
            }
            else{
                y += s[j];
            }
        }
        mae[mp(x, y)]++;
    }
    rep(i,1ll<<n){
        string x, y;
        rep(j,n){
            if ((i>>j)&1){
                x += t[j];
            }
            else{
                y += t[j];
            }
        }
        ushiro[mp(x, y)]++;
    }
    ll ans = 0;
    for(auto p:mae){
        //cout << p.F.F << " " << p.F.S << " " << p.S << " " << ushiro[p.F] << endl;
        ans += p.S * ushiro[p.F];
    } 
    cout << ans << endl;
}   
