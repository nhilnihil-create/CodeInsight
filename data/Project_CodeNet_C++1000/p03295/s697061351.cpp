#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> land(m);

    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        land[i] = {tmp2, tmp1};
    }

    sort(land.begin(), land.end());

    int bridge = 0;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        if (land[i].second > bridge)
        {
            bridge = land[i].first - 1;
            count++;
        }
    }

    cout << count << endl;
}