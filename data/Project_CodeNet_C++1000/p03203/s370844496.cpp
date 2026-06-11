#include <bits/stdc++.h>

using namespace std;

set <int> Se[200001];

int main()
{
    int n, m, k, X, Y, Mi=20000000, t=0;
    cin >> m >> n >> k;
    set <int> :: iterator it;
    for (int i = 0; i < k; i++)
    {
        cin >> X >> Y;
        X--;
        Y--;
        Se[Y].insert(X);
    }
    for (int i = 0; i < n; i++)
    {
        Se[i].insert(m);
    }
    if (Se[0].find(1) != Se[0].end())
    {
        cout << 1;
        return 0;
    }
    X=1;
    Y=0;
    t = 1;
    while (X < m && Y < n)
    {
        it = Se[Y].upper_bound(X);
        Mi = min(Mi, *it-X-1+t);
        if (Y == n-1)
        {
            break;
        }
        if (Se[Y+1].find(X) == Se[Y+1].end())
        {
            Y++;
        }
        it = Se[Y].upper_bound(X);
        Mi = min(Mi, *it-X-1+t);
        X++;
        t++;
    }
    cout << Mi+1;
    return 0;
}
