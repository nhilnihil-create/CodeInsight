#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define fast ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define umll unordered_map<ll,ll>
#define mll map<ll,ll>
#define forr(i,p,n) for(ll i=p;i<(ll)n;i++)
#define fore(i,n,k) for(ll i=n-1;i>=k;i--)
#define MAXN 1000003
typedef long long ll;
using namespace std;
ll mult(ll a, ll b, ll p = MOD) {return ((a % p) * (b % p)) % p;}
ll add(ll a, ll b, ll p = MOD) {return (a % p + b % p) % p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
ll inv_euclid(ll a, ll m = MOD) {ll m0 = m; ll y = 0, x = 1; if (m == 1)return 0; while (a > 1) {ll q = a / m; ll t = m; m = a % m, a = t; t = y; y = x - q * y; x = t;} if (x < 0)x += m0; return x;}
using namespace __gnu_pbds;
typedef tree<ll, null_type, less< ll>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
void functiontosolve()
{
    ll n;
    cin >> n;
    ll a[n], b[n], c[n];
    forr(i, 0, n) {
        ll x, y, z;
        cin >> x >> y >> z;
        if (i == 0 ) {
            a[0] = x;
            b[0] = y;
            c[0] = z;
            continue;
        }
        a[i] = max(b[i - 1], c[i - 1]) + x;
        b[i] = max(a[i - 1], c[i - 1]) + y;
        c[i] = max(a[i - 1], b[i - 1]) + z;
    }
    cout << max(a[n - 1], max(b[n - 1], c[n - 1])) << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    test  = 1;
    forr(i, 1, test + 1) {
        functiontosolve();
    }
    return 0;
}