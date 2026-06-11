#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define mod (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void print(bool f)
{
    cout << (f ? "Yes" : "No") << endl;
}

void Print(bool f)
{
    cout << (f ? "YES" : "NO") << endl;
}

ll combination(ll n)
{
    return n * (n - 1) / 2;
}

int main(void)
{
    ll n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    vll sum(n + 1, 0);
    map<ll, ll> mp;
    mp[0]++;
    rep(i, 1, n + 1) sum[i] = sum[i - 1] + a[i - 1], mp[sum[i]]++;
    ll ans = 0;
    for (auto x : mp)
    {
        if (x.second >= 2)
            ans += combination(x.second);
    }
    cout << ans << endl;
}