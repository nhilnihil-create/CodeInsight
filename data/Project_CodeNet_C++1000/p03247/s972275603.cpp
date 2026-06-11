#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
 
 
using namespace std;
 
 
const int N =  1e3 + 123;
const int MAXN = 2e5;
const int brd = 32;
const ull inf = 1e18 + 7;



ll n, m, X[N], Y[N], pw[40], ln[N]; 
char ans[N][40];


void rec(ll id, ll x, ll y, ll ind) {
    if (ind == 0)
        return;
    if (y > x && y > -x) {
        ans[id][ind] = 'U';
        rec(id, x, y - ln[ind], ind - 1);
    } else if (y > x && y < -x) {
        ans[id][ind] = 'L';
        rec(id, x + ln[ind], y, ind - 1);
    } else if (y < x && y < -x) {
        ans[id][ind] = 'D';
        rec(id, x, y + ln[ind], ind - 1);
    } else {
        ans[id][ind] = 'R';
        rec(id, x - ln[ind], y, ind - 1);
    }
}
 
 
int main() {
    cin >> n;
    bool s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
        if ((X[i] + Y[i]) % 2 == 0)
            s1 = 1;
        else
            s2 = 1;
    }
    if (s1 && s2)
        return cout << -1, 0;
    if (s1) {
        for (int i = 1; i <= n; i++)
            X[i]--;
    }
    ll t = 1;
    for (int i = 0; i <= brd; i++) {
        ln[i + 1] = t;
        t *= 2;
    }
    m = brd + 1;
    for (int i = 1; i <= n; i++)
        rec(i, X[i], Y[i], m);
    if (s1) {
        m++;
        ln[m] = 1;
        for (int i = 1; i <= n; i++)
            ans[i][m] = 'R';
    }
    cout << m << "\n";
    for (int i = 1; i <= m; i++)
        cout << ln[i]  << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j];
        cout << "\n";
    }
}
