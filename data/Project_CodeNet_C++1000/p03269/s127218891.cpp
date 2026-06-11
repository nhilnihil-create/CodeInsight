#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct edge
{
    int u,v,w;
};
vector <edge> ans;

int n,L;

int main()
{
   // freopen("file.inp","r",stdin);
    cin >> L;
    if (L == 2)
    {
        cout << "2 2" << endl;
        cout << "1 2 0" << endl;
        cout << "1 2 1" << endl;
        return 0;
    }
    L--;
    int d = 1;
    while (4 * d <= L)
    {
        d <<= 1;
    }
    for (int i = 1; i <= 19; i++)
    {
        ans.push_back({i, i + 1, d});
        ans.push_back({i, i + 1, 0});
        d >>= 1;
        n = i + 1;
        if (d == 0) break;
    }
    d = 1;
    while (2 * d <= L)
    {
        d <<= 1;
    }
    for (int i = 1 ; n - i - 1 >= 0; i++)
    {
        if (((L >> (n - i - 1)) & 1) == 1)
        {
            ans.push_back({1, i + 1, d});
            d += 1 << (n - i - 1);
        }
    }
    ans.push_back({1, n, L});
    cout << n << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].u << " " << ans[i].v << " " << ans[i].w << endl;
    }
    return 0;
}
