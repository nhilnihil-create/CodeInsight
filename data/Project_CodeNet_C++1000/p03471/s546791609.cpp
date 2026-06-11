#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i <= n; ++i)
using namespace std;
int main()
{
    int N, Y;
    cin >> N >> Y;
    REP(x, N)
    {
        REP(y, N - x)
        {
            int z = N - x - y;
            if ((x * 10000 + y * 5000 + z * 1000) == Y)
            {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
