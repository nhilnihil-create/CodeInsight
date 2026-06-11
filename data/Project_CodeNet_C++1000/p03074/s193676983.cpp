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
    int n, k;
    cin >> n >> k;
    int offset;
    vector<int> vs;
    {
        string s;
        cin >> s;
        int count = 0;
        int prev = s[0];
        for (auto ch : s)
        {
            if (prev == ch)
            {
                count++;
            }
            else
            {
                vs.push_back(count);
                count = 1;
                prev = ch;
            }
        }
        vs.push_back(count);
        offset = s[0] == '0' ? 0 : 1;
        // 最初は 1 から始まると考えたほうが楽
        if (s[0] == '0')
        {
            vs.insert(vs.begin(), 0);
        }
        if (s.back() == '0')
        {
            vs.push_back(0);
        }
    }

    vs.insert(vs.begin(), 0);
    for (int i = 1; i < vs.size(); i++)
    {
        vs[i] += vs[i - 1];
    }

    const auto width = 2 * k + 1;

    if (vs.size() <= width + 1)
    {
        cout << n << endl;
    }
    else
    {
        int ans = 0;
        for (int i = width; i < vs.size(); i += 2)
        {
            ans = max(ans, vs[i] - vs[i - width]);
        }
        cout << ans << endl;
    }
}
