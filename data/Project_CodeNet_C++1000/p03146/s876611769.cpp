#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s;
    cin >> s;
    map<int, int> mp;
    int count = 0;
    while (1)
    {
        ++count;
        if (mp[s] == 1)
        {
            cout << count << endl;
            return 0;
        }
        mp[s]++;
        if (s % 2 == 0)
        {
            s /= 2;
        }
        else
        {
            s = 3 * s + 1;
        }
    }
}