#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int m, k;
    cin >> m >> k;

    if (k >= pow(2, m))
    {
        cout << -1 << endl;
        return 0;
    }

    if (m == 1 && k == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;

    if (k == 0)
    {
        for (int i = 0; i < pow(2, m); i++)
        {
            ans.push_back(i);
            ans.push_back(i);
        }
    }
    else
    {
        for (int i = 0; i < pow(2, m); i++)
        {
            if (i == k)
                continue;

            ans.push_back(i);
        }
        ans.push_back(k);
        for (int i = pow(2, m) - 1; i >= 0; i--)
        {
            if (i == k)
                continue;

            ans.push_back(i);
        }
        ans.push_back(k);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        i == 0 ? (cout << ans[i]) : (cout << ' ' << ans[i]);
    }
    cout << endl;
}