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
long long cost[5100][5100];

int main()
{
    int n;
    long long a, b;
    cin >> n >> a >> b;
    vector<int> p(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    long long inf = 1e18;
    p[n + 1] = n + 1;
    cost[0][0] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        cost[i][i] = inf;
        for (int j = 0; j < i; j++)
        {
            if (p[i] > p[j])
            {
                cost[i][i] = min(cost[i - 1][j], cost[i][i]);
            }
            cost[i][j] = cost[i - 1][j] + (p[i] > p[j] ? a : b);
        }
    }

    cout << cost[n + 1][n + 1] << endl;
    return 0;
}