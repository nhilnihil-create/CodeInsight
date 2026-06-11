#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> e(n+1);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<int> d(n+1);
    using P = pair<int, int>;
    function<void(int, vector<int> &)> dfs = [&](int s, vector<int> &d)
    {
        queue<P> que;
        que.push(P(0, s));
        while(!que.empty())
        {
            P p = que.front();
            int v = p.second;
            int cost = p.first;
            que.pop();
            for(auto next : e[v])
            {
                if(next != s && d[next] == 0)
                {
                    que.push(P(cost+1, next));
                    d[next] = cost + 1;
                }
            }
        }
    };
    dfs(1, d);
    int ma = 0;
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(ma < d[i])
        {
            ma = d[i];
            pos = i;
        }
    }
    vector<int> d2(n+1);
    dfs(pos, d2);
    int ma2 = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(ma2 < d2[i])
        {
            ma2 = d2[i];
        }
    }
    if((ma2+1) % 3 != 2)
    {
        cout << "First" << endl;
    }
    else cout << "Second" << endl;
}