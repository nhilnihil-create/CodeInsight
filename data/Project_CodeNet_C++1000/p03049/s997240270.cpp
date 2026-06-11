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
    int ans = 0;

    array<int64_t, 3> cs{ 0, 0, 0 };

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size() - 1; j++)
        {
            if (s.substr(j, 2) == "AB")
            {
                ans++;
            }
        }
        if (s.front() == 'B' && s.back() == 'A')
        {
            cs[0]++;
        }
        else if (s.front() == 'B')
        {
            cs[1]++;
        }
        else if (s.back() == 'A')
        {
            cs[2]++;
        }
    }

    if (cs[0] == 0)
    {
        cout << ans + min(cs[1], cs[2]) << endl;
    }
    else
    {
        if (cs[1] + cs[2] > 0)
        {
            cout << (ans + cs[0] + min(cs[1], cs[2])) << endl;
        }
        else
        {
            cout << (ans + cs[0] - 1 + min(cs[1], cs[2])) << endl;
        }
    }
}
