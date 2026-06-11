#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

vi adj[200001];
int dst[200001];
int n, r = 1;

void dfs(int x, int p)
{
    for (int y : adj[x])
    {
        if (y == p) continue;
        dst[y] = dst[x] + 1;
        if (dst[y] > dst[r])
            r = y;
        dfs(y, x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n == 1)
        return cout << "First\n", 0;

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    dst[r] = 0;
    dfs(r, -1);
    if ((dst[r] - 1) % 3 == 0)
        cout << "Second";
    else
        cout << "First";
}
