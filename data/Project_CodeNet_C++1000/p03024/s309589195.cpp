//mo algo (no square root decomposition)
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define in insert
#define pb push_back
#define int long long int
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
inline ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
inline ll power(ll a, ll n, ll m)
{
    if (n == 0)
        return 1;
    ll p = power(a, n / 2, m);
    p = (p * p) % m;
    if (n % 2)
        return (p * a) % m;
    else
        return p;
}
const ll MOD = 998244353;
#define int long long int

int32_t main()
{
    IOS;
    string s;
    cin >> s;
    int n = s.size();
    int y = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o')
            y++;
    n = 15 - n;
    if (n + y >= 8)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}