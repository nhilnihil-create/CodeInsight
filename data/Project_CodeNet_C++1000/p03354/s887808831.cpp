#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int p[100000];

struct UF
{
    vector<int> r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
	
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
	
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i], p[i]--;

    UF uf(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.u(x, y);
    }
    vector<vector<int>> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        a[uf.f(i)].push_back(i);
        b[uf.f(i)].push_back(p[i]);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i)
    {
        sort(all(a[i]));
        sort(all(b[i]));
        vector<int> c(a[i].size());
        c.resize(set_intersection(all(a[i]), all(b[i]), c.begin()) - c.begin());
        sol += c.size();
    }
    cout << sol;
}
