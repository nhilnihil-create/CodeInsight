#include <iostream>

using namespace std;
int m, k;
int main()
{
    cin >> m >> k;

    if(((1 << m) <= k) || (m == 1 && k != 0) || (m == 0 && k != 0))
        cout << -1;
    else if(m == 1 && k == 0)
    {
        cout << "0 0 1 1";
    }
    else if(m == 0 && k == 0)
    {
        cout << "0 0";
    }
    else
    {
        int n = 1 << m;
        --n;

        for(int i = 0; i <= n; ++i)
        {
            if(i == k)
                continue;

            cout << i << ' ';
        }

        cout << k << ' ';

        for(int i = n; i >= 0; --i)
        {
            if(i == k)
                continue;

            cout << i << ' ';
        }

        cout << k;
    }

    return 0;
}
