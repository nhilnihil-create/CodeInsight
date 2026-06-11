#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2e5 + 5;

vector<int> v[Nmax];
bool used[Nmax];
int x, y, i, n, m, cnt[Nmax][2], node;
queue<int> bad;
char a[Nmax];

int main()
{
//    freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    cin >> (a+1);

    for(i=1; i<=m; ++i)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=1; i<=n; ++i)
        for(auto it : v[i])
            ++cnt[i][a[it] - 'A'];

    for(i=1; i<=n; ++i)
        if(!cnt[i][0] || !cnt[i][1])
            bad.push(i), used[i] = 1;

    while(!bad.empty())
    {
        node = bad.front();
        bad.pop();

        for(auto it : v[node])
        {
            --cnt[it][a[node] - 'A'];
            if(!cnt[it][a[node] - 'A'] && !used[it])
            {
                used[it] = 1;
                bad.push(it);
            }
        }
    }

    for(i=1; i<=n; ++i)
        if(!used[i])
        {
            cout << "Yes\n";
            return 0;
        }
    cout << "No\n";
    return 0;
}
