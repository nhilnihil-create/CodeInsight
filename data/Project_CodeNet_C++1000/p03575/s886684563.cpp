
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

ll n, m;

bool bfs(vllll path)
{
    vb pass(n, false);
    pass[0] = true;
    queue<int> q;
    q.push(0);
    int cnt = 1;
    while (!q.empty())
    {
        int sp = q.front();
        q.pop();
        rep(i, 0, n)
        {
            if (path[sp][i] && !pass[i])
            {
                q.push(i);
                pass[i] = true;
                cnt++;
            }
        }
        if (cnt == n)
            return false;
    }
    return true;
}

int main(void)
{
    cin >> n >> m;
    vll a(m), b(m);
    vllll path(n, vll(n));
    rep(i, 0, m)
    {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        path[a[i]][b[i]] = 1;
        path[b[i]][a[i]] = 1;
    }

    ll ans = 0;
    rep(i, 0, m)
    {
        path[a[i]][b[i]] = 0;
        path[b[i]][a[i]] = 0;

        if (bfs(path))
            ans++;

        path[a[i]][b[i]] = 1;
        path[b[i]][a[i]] = 1;
    }
    cout << ans << endl;
}