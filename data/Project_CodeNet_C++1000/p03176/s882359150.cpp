#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int BASE = 1 << 20;
int N;
ll tree[2 * BASE + 9];
ll h[200009], a[200009], dp[200009];
ll ans;

void set_max(int l, int r, ll val)
{
    int v = l + BASE - 1;
    int w = r + BASE - 1;

    tree[v] = max(val, tree[v]);
    tree[w] = max(val, tree[w]);
    while (v / 2 != w / 2)
    {
        if (v % 2 == 0) tree[v + 1] = max(tree[v + 1], val);
        if (w % 2 == 1) tree[w - 1] = max(tree[w - 1], val);

        v /= 2;
        w /= 2;
    }
}

ll query(int v)
{
    v += BASE - 1;

    ll ret = 0;
    while (v != 0)
    {
        ret = max(ret, tree[v]);
        v /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++)
    {
        dp[i] = query(h[i]) + a[i];

        set_max(h[i] + 1, N + 1, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}