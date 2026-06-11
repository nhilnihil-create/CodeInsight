#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vs(n);
    for (auto& v : vs)
    {
        cin >> v;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int max_index = -1;
        for (int j = 0; j < vs.size(); j++)
        {
            if (j + 1 == vs[j])
            {
                max_index = j + 1;
            }
        }
        if (max_index == -1)
        {
            break;
        }
        else
        {
            ans.push_back(max_index);
            vs.erase(vs.begin() + (max_index - 1));
        }
    }
    if (ans.size() == n)
    {
        reverse(ans.begin(), ans.end());
        for (auto v : ans)
        {
            cout << v << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}
