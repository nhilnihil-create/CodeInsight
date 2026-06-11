#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, c, ans = 0, b[20];
    cin >> n >> m >> c;

    for (int in = 0; in < m; in++)
    {
        cin >> b[in];
    }

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        int a[20];
        for (int in = 0; in < m; in++)
        {
            cin >> a[in];
            temp += b[in] * a[in];
        }

        if (temp + c > 0) ans++;
    }

    cout << ans << endl;
}