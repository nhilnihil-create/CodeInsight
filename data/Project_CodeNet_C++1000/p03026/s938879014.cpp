#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<int> ans(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    vector<int> c(n);
    rep(i, n)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    ll s = -c.back();
    for (int i = 0; i < n; i++)
    {
        s += c[i];
    }
    cout << s << endl;
    queue<int> que;
    for (int i = n - 1; i >= 0; i--)
    {
        que.push(c[i]);
    }
    queue<int> que2;
    que2.push(0);
    while (!que2.empty())
    {
        int it = que2.front();
        que2.pop();
        ans[it] = que.front();
        que.pop();
        for (auto i : v[it])
        {
            if (ans[i] == 0)
            {
                que2.push(i);
            }
        }
    }
    rep(i, n)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}