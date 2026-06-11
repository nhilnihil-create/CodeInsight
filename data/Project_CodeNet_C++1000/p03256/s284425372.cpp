#include<bits/stdc++.h>

using namespace std;

const long long MaxN = 2e5 + 17;
int arr[MaxN];
int amount[MaxN][2];
vector<int> lst[MaxN];
bool used[MaxN];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, m;
    cin >> n >> m >> s;

    for(int i = 0; i < n; ++i)
        arr[i] = (s[i] - 'A');

    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        ++amount[x - 1][arr[y - 1]];
        ++amount[y - 1][arr[x - 1]];

        lst[x - 1].push_back(y - 1);
        lst[y - 1].push_back(x - 1);
    }

    stack<int> ver;

    for(int i = 0; i < n; ++i)
        if(!amount[i][0] || !amount[i][1])
        {
            ver.push(i);
            used[i] = true;
        }

    while(!ver.empty())
    {
        int t = ver.top();
        ver.pop();

        for(int i = 0; i < lst[t].size(); ++i)
        {
            int go = lst[t][i];

            if(!used[go])
            {
                --amount[go][arr[t]];

                if(!amount[go][0] || !amount[go][1])
                {
                    ver.push(go);
                    used[go] = true;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
        if(!used[i])
            return cout << "Yes\n", 0;

    cout << "No\n";








}

