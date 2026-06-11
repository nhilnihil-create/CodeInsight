#include <bits/stdc++.h>

using namespace std;

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q[265000];
set <pair<int,int>> Se[265000];

int main()
{
    int n, l, a, Si, b, S, I, Ma=0;
    cin >> n;
    Si = (1 << n);
    for (int i = 0; i < Si; i++)
    {
        cin >> a;
        Q[i].push({a,i});
        Se[i].insert({a,i});
        while (Q[i].size() > 2)
        {
            Se[i].erase(Se[i].find({Q[i].top().first, Q[i].top().second}));
            Q[i].pop();
        }
        S = 0;
        while (Q[i].size() > 0)
        {
            S += Q[i].top().first;
            I = Q[i].top().second;
            for (int u = 0; u < n; u++)
            {
                if (((1 << u) & i) == 0)
                {
                    b = i | (1 << u);
                    if (Se[b].find({Q[i].top().first,I}) == Se[b].end())
                    {
                        Q[b].push({Q[i].top().first, I});
                        Se[b].insert({Q[i].top().first, I});
                        while (Q[b].size() > 2)
                        {
                            Se[b].erase(Se[b].find({Q[b].top().first,Q[b].top().second}));
                            Q[b].pop();
                        }
                    }
                }
            }
            Se[i].erase(Se[i].find({Q[i].top().first,I}));
            Q[i].pop();
        }
        if (i != 0)
        {
            Ma = max(Ma, S);
            cout << Ma << "\n";
        }
    }
    return 0;
}
