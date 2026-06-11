#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp, res = 0;
    cin >> n;
    unordered_map<int, int> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        m[tmp]++;
    }

    for(auto i : m)
    {
        if(i.first > i.second)
        {
            res += i.second;
        } else if(i.first < i.second)
        {
            res += i.second - i.first;
        }
    }

    cout << res << "\n";
}
