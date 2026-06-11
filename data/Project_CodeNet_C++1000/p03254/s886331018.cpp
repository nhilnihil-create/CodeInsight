#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;
    int ans = 0;

    int a[105];
    for (int i = 0; i < 105; i++)
    {
        a[i] = 1000000001;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 105);

    for (int i = 0; i < N; i++)
    {
        x -= a[i];
        if (x < 0)
        {
            break;
        }
        else
        {
            ans++;
        }
    }

    if (x > 0)
        ans--;

    cout << ans << endl;

    return 0;
}