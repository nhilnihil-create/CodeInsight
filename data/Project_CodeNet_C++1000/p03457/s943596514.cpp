#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int t, x, y;
int main()
{
    int n;
    cin >> n;
    // bool flg = true;
    int _t = 0, _x = 0, _y = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t >> x >> y;
        int dt = t - _t;
        int dd = abs(x - _x) + abs(y - _y);
        // cout << dt << "," << dd << endl;
        if (dd <= dt && ((dt % 2) == (dd % 2)))
        {
            _x = x;
            _y = y;
            _t = t;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}