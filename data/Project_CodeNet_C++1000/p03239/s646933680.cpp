#include <iostream>

using namespace std;

void solve(int n, int t)
{
    int c1, t1;
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> t1;

        if (t1 <= t)
        {
            if (cost == 0)
            {
                cost = c1;
            }
            else if (c1 < cost)
            {
                cost = c1;
            }
        }
    }

    if (cost == 0)
    {
        cout << "TLE" << endl;
    }
    else
    {
        cout << cost << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    
    int n , t;

    cin >> n >> t;

    solve(n, t);
    
    return 0;
}