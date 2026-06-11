#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int f(int i)
{
    if (i % 2 == 0)
        return i / 2;
    else
        return 3 * i + 1;
}

int main()
{
    int s;
    cin >> s;
    vector<int> a;
    for (int i = 1; i <= 1000000; i++)
    {
        if (i == 1)
            a.push_back(s);
        else
        {
            int ai = f(a[i - 2]);
            int cnt = count(a.begin(), a.end(), ai);
            if (cnt > 0)
            {
                cout << i << endl;
                return 0;
            }
            else
                a.push_back(ai);
        }
    }
    return 0;
}