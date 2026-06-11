#include <bits/stdc++.h>
using namespace std;
bool m_ans(int x, int y, int *X, int n, int *Y, int m)
{
    int maxX = X[0], minY = Y[0];
    for (int i = 1; i < n; ++i)
    {
        if (X[i] > maxX)
            maxX = X[i];
    }
    maxX += 1;
    for (int i = 1; i < m; ++i)
    {
        if (Y[i] < minY)
        {
            minY = Y[i];
        }
    }
    if (maxX > minY)
        return true;
    else
    {
        for (int z = maxX; z <= minY; ++z)
        {
            if (z > x && z <= y)
                return false;
        }
        return true;
    }
}
int main()
{
    int n, m, x, y;
    bool ans;
    cin >> n >> m >> x >> y;
    int X[n], Y[m];
    for (int &i : X)
        cin >> i;
    for (int &i : Y)
        cin >> i;
    ans = m_ans(x, y, X, n, Y, m);
    if (ans)
        cout << "War" << endl;
    else
        cout << "No War" << endl;
}