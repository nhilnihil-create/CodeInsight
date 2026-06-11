#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2e5;

int n, m;

vector <int> v[MaxN];
string s;

bool deleted[MaxN];

set<pair<int, int> > S;

int cnt[2][MaxN];

void popV(int x)
{
    deleted[x] = true;

    for(int to : v[x])
        if(!deleted[to])
        {
            S.erase(make_pair(min(cnt[0][to], cnt[1][to]), to));
            if(s[x] == 'A')
                --cnt[0][to];
            else
                --cnt[1][to];
            S.insert(make_pair(min(cnt[0][to], cnt[1][to]), to));
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    cin >> s;

    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;

        v[x].push_back(y);
        v[y].push_back(x);

        if(s[x] == 'A')
            ++cnt[0][y];
        else
            ++cnt[1][y];

        if(s[y] == 'A')
            ++cnt[0][x];
        else
            ++cnt[1][x];
    }

    for(int i = 0; i < n; ++i)
        S.insert(make_pair(min(cnt[0][i], cnt[1][i]), i));

    while(!S.empty() && (*S.begin()).first == 0)
    {
        int x = (*S.begin()).second;
        S.erase(S.begin());

        popV(x);
    }

    if(S.empty())
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}
