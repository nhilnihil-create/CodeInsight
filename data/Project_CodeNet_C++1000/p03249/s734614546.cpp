#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <chrono>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> d(N);
    vector<pair<int, int>> t;
    map<long long, int> a;
    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
        a[d[i]] = i;
    }

    vector<int> weigtht(N, 1);
    for (int it = 0; it < N - 1; it++)
    {
        auto target = a.rbegin();
        int i = target->second;
        long long dis = d[i];
        long long next = dis - (N - weigtht[i]) + weigtht[i];
        if (a.find(next) == a.end() || a[next] == i)
        {
            cout << "-1" << endl;
            return 0;
        }
        int j = a[next];
        weigtht[j] += weigtht[i];
        t.push_back({i, j});
        a.erase(--a.end());
    }

    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; i++)
    {
        g[t[i].first].push_back(t[i].second);
        g[t[i].second].push_back(t[i].first);
    }
    vector<int> valid(N, -1);
    valid[0] = 0;
    vector<int> que(1, 0);
    for (int i = 0; i < (int)que.size(); i++)
    {
        for (int &j : g[que[i]])
        {
            if (valid[j] == -1)
            {
                que.push_back(j);
                valid[j] = valid[que[i]] + 1;
            }
        }
    }

    long long int node_0_d = 0;
    for (int i = 0; i < N; i++)
    {
        if (valid[i] != -1)
        {
            node_0_d += valid[i];
        }
    }

    if ( node_0_d != d[0] )
    {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < N - 1; i++)
    {
        cout << t[i].first + 1 << " " << t[i].second + 1 << endl;
    }
    return 0;
}