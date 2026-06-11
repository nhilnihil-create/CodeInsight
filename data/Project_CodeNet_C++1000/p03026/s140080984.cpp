#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N - 1), b(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> c(N);
    for (int i = 0; i < N; i++)
    {
        cin >> c.at(i);
    }

    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; i++)
    {
        tree.at(a.at(i) - 1).push_back(b.at(i) - 1);
        tree.at(b.at(i) - 1).push_back(a.at(i) - 1);
    }
    sort(c.rbegin(), c.rend());

    vector<int> res(N, -1);
    res.at(0) = c.at(0);
    int s = 0;
    int idx = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : tree.at(v))
        {
            if (res.at(u) > 0)
                continue;
            res.at(u) = c.at(idx);
            s += c.at(idx);
            idx++;
            q.push(u);
        }
    }
    cout << s << endl;
    for (int i = 0; i < N; i++)
    {
        cout << res.at(i) << " ";
    }
    cout << endl;
    return 0;
}
