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
#define _USE_MATH_DEFINES
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
    int Q;
    cin >> Q;
    rep(q,Q){
        int k;
        cin >> k;
        ll dmc = 0;
        ll d = 0, m = 0, dm = 0;
        rep(i,n){
            if (s[i]=='D'){
                d++;
            }
            if (s[i]=='M'){
                m++;
                dm += d;
            }
            if (i-k>=0){
                if (s[i-k]=='D'){
                    d--;
                    dm -= m;
                }
                if (s[i-k]=='M'){
                    m--;
                }
            }
            if (s[i]=='C'){
                dmc += dm;
            }
        }
        cout << dmc << endl;
    }
}
