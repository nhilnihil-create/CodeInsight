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

const ll mod = 1e9 + 7;
const ll infl = 1e17;

typedef unsigned long long ull;



int main()
{
    ll n;
    cin >> n;
    if (n==3){
        cout << "2 5 63" << endl;
        return 0;
    }
    ll k = n / 8;
    ll l = n % 8;
    rep(i,k){
        ll x = 12 * i;
        cout << x + 2 << " ";
        cout << x + 3 << " ";
        cout << x + 4 << " ";
        cout << x + 6 << " ";
        cout << x + 8 << " ";
        cout << x + 9 << " ";
        cout << x + 10 << " ";
        cout << x + 12 << " ";
    }
    ll x = 12 * k;
    if (l%2==1){
        cout << x + 6 << " ";
        l--;
    }
    if (l>=2){
        cout << x + 2 << " " << x + 4 << " ";
        l -= 2;
    }
    if (l >= 2)
    {
        cout << x + 3 << " " << x + 9 << " ";
        l -= 2;
    }
    if (l >= 2)
    {
        cout << x + 8 << " " << x + 10 << " ";
        l -= 2;
    }
    cout << endl;
}
