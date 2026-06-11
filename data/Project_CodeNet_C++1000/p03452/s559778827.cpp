#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> l, r, d;

vector<queue<pair<int, long long> > > to;

int main()
{
    cin >> n >> m;
    l = r = d = vector<int>(m);
    to.resize(n);
    for (int i=0; i<m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;
        r[i]--;
        to[l[i]].push(make_pair(r[i], d[i]));
        to[r[i]].push(make_pair(l[i], -d[i]));
    }

    vector<bool> flg(n, false);
    vector<long long> x(n, 0);
    for (int i=0; i<n; i++)
    {
        if (flg[i]) continue;
        flg[i] = true;
        queue<pair<int, long long> > toSearch;

        while (!to[i].empty())
        {
            toSearch.push(to[i].front());
            flg[to[i].front().first] = true;
            to[i].pop();
        }

        while (!toSearch.empty())
        {
            int st = toSearch.front().first;
            long long xtmp = toSearch.front().second;
            toSearch.pop();
            x[st] = xtmp;
            while(!to[st].empty())
            {
                if (!flg[to[st].front().first])
                {
                    toSearch.push(make_pair(to[st].front().first, xtmp + to[st].front().second));
                    flg[to[st].front().first] = true;
                }
                to[st].pop();
            }
        }
    }

    for (int j=0; j<m; j++)
    {
        if (x[r[j]] - x[l[j]] != d[j])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
