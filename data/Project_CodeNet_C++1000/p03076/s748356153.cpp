#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> dish(5, make_pair(0, 0));
    for (int i = 0; i < 5; i++)
    {
        cin >> dish[i].second;
        dish[i].first = -(dish[i].second % 10);
        if (dish[i].first == 0)
        {
            dish[i].first -= 10;
        }
    }
    sort(dish.begin(), dish.end());
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans += dish[i].second + 10 + dish[i].first;
        if (i == 4)
        {
            ans -= dish[i].first + 10;
        }
    }
    cout << ans << endl;
}