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
    int L;
    cin >> L;
    typedef pair<int, int> edge;
    vector<pair<edge, int>> g;
    int N = 20;
    for (int i = 2; i < N; i++)
    {
        g.push_back({edge(i, i + 1), 0});
        g.push_back({edge(i, i + 1), 1 << (N - i - 1)});
    }

    int st = 0;
    for (int i = 2; i <= N; i++)
    {
        while (L - st >= (1 << (N - i)))
        {
            g.push_back({edge(1, i), st});
            st += 1 << (N - i);
        }
    }
    cout << 20 << " " << g.size() << endl;
    for (int i = 0; i < g.size(); i++)
    {
        cout << g[i].first.first << " " << g[i].first.second << " " << g[i].second << endl;
    }
    return 0;
}