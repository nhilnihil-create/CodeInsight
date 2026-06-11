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

int main(void)
{
    ll n;
    cin >> n;
    vll a;
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    rep(i, 0, a.size())
    {
        rep(j, 0, 3)
        {
            if (a[i] * 10 + 2 * j + 3 <= n)
                a.push_back(a[i] * 10 + 2 * j + 3);
        }
    }
    ll cnt = 0;
    rep(i, 0, a.size())
    {
        vll f(3, false);
        while (a[i])
        {
            f[(a[i] % 10 - 3) / 2] = true;
            a[i] /= 10;
        }
        rep(j, 0, 3)
        {
            if (!f[j])
                break;
            if (j == 2)
                cnt++;
        }
    }
    cout << cnt << endl;
}