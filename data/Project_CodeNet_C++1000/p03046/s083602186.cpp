#include <iostream>

using namespace std;

int main()
{
    int m;
    long long k, p = 1ll;

    cin >> m >> k;

    for (int i = 0;i < m;i++) p *= 2ll;

    if (k >= p) cout << -1 << endl;
    else if (m == 1)
    {
        if (k == 0)
        {
            cout << "0 0 1 1" << endl;
        }else
        {
            cout << -1 << endl;
        }
    }else
    {
        for (long long i = 0ll;i < p;i++)
        {
            if (i != k) cout << i << " ";
        }
        cout << k << " ";
        for (long long i = p-1;i >= 0ll;i--)
        {
            if (i != k) cout << i << " ";
        }
        cout << k << endl;
    }
}