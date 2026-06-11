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

int search(int b,int e,vll& s){
    int MIN = b + 1;
    int MAX = e - 1;
    if (MIN==MAX)
        return MIN;
    while (1){
        if (MIN+1==MAX)
            break;
        int m = (MIN + MAX) / 2;
        if (s[m]-s[b]==s[e]-s[m]){
            return m;
        }
        else if (s[m]-s[b]<s[e]-s[m]){
            MIN = m;
        }
        else{
            MAX = m;
        }
    }
    return MIN;
}

int main()
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll s(n + 1,0);
    rep(i, n) s[i + 1] = s[i] + a[i];
    ll ans = infl;
    repf(i,2,n-1){
        int idx = search(0, i, s);
        ll x0 = (s[i] - s[idx]) ,x1= (s[idx] - s[0]);
        ll x2 = -infl, x3 = infl;
        idx++;
        if (idx<i){
            x2 = (s[i] - s[idx]) ,x3= (s[idx] - s[0]);
        }
        ll xx0, xx1;
        if (abs(x0-x1)>=abs(x2-x3)){
            xx0 = min(x2,x3);
            xx1 = max(x2,x3);
        }
        else{
            xx0 = min(x0, x1);
            xx1 = max(x0, x1);
        }
/*
        cout << "start : " << i << endl;
        cout << "x idx : " << idx-1 << endl;
        cout << x0 << " " << x1 << " " << x2 << " " << x3 << endl;
        cout << xx0 << " " << xx1 << endl;
 */

        idx = search(i, n, s);
        ll y0 = (s[n] - s[idx]) ,y1= (s[idx] - s[i]);
        ll y2 = -infl, y3 = infl;
        idx++;
        if (idx<n){
            y2 = (s[n] - s[idx]) ,y3 = (s[idx] - s[i]);
        }
        ll yy0, yy1;
        if (abs(y0-y1)>=abs(y2-y3)){
            yy0 = min(y2, y3);
            yy1 = max(y2, y3);
        }
        else{
            yy0 = min(y0, y1);
            yy1 = max(y0, y1);
        }

/*
        cout << "y idx : " << idx-1 << endl;
        cout << y0 << " " << y1 << " " << y2 << " " << y3 << endl;
        cout << yy0 << " " << yy1 << endl;
 */
        ans = min(ans, max(xx1, yy1) - min(xx0, yy0));
    }
    cout << ans << endl;
}   
