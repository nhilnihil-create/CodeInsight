// https://atcoder.jp/contests/abc116/tasks/abc116_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s;
    cin >> s;

    vector<bool> used(1000001, false);
    used[s] = true;
    for (long i = 2; i <= 1000000; i++)
    {
        if (s & 1)
        {
            s = s * 3 + 1;
        }
        else
        {
            s /= 2;
        }
        if (used[s])
        {
            cout << i << endl;
            return 0;
        }
        used[s] = true;
    }
}
