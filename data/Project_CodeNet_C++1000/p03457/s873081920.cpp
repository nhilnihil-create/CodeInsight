#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int t = 0, x = 0, y = 0;
    int nt, nx, ny;
    for (int i = 0; i < n; ++i)
    {
        cin >> nt >> nx >> ny;
        int dt = nt - t;
        int dr = abs(nx - x) + abs(ny - y);
        if ((dt % 2) == (dr % 2) && dt >= dr)
        {
            t = nt, x = nx, y = ny;
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
