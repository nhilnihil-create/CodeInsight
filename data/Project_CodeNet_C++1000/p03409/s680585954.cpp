#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> red, blue;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        red.emplace_back(a, b);
    }
    sort(red.begin(), red.end());
    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;
        blue.emplace_back(c, d);
    }
    sort(blue.begin(), blue.end());
    vector<int> checked(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int index1 = -1;
        for (int j = 0; j < n; j++)
        {
            if (red[j].first > blue[i].first)
            {
                index1 = j;
                break;
            }
        }
        if (index1 < 0)
        {
            index1 = n;
        }

        int maxy = -1;
        int index = -1;

        for (int j = 0; j < index1; j++)
        {
            if (checked[j] > 0)
            {
                continue;
            }
            if (blue[i].second < red[j].second)
            {
                continue;
            }
            maxy = max(maxy, red[j].second);
            if (red[j].second == maxy)
            {
                index = j;
            }
        }
        if (index != -1)
        {
            ans++;
            checked[index]++;
        }
    }
    cout << ans << endl;
    return 0;
}