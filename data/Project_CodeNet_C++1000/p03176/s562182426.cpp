#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 2e5 + 5;

int T[Nmax];
int pos[Nmax];
int a[Nmax];
int n,ans;

void update(int i, int val)
{
    while (i <= n)
    {
        T[i] = max(T[i], val);
        i += i & -i;
    }
}

int get(int i)
{
    int res = 0;
    while (i)
    {
        res = max(res, T[i]);
        i -= i & -i;
    }
    return res;
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int res = get(pos[i]) + a[i];
        update(pos[i], res);
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}
