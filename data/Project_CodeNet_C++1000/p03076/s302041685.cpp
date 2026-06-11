#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    int b[5];
    for (size_t i = 0; i < 5; i++)
    {
        b[i] = ((a[i] - 1) / 10 + 1) * 10;
    }
    int ans = 100000;
    for (size_t i = 0; i < 5; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < 5; j++)
        {
            if (i != j)
            {
                sum += b[j];
            }
            else
            {
                sum += a[j];
            }
        }
        ans = min(ans, sum);

        /* code */
    }
    cout << ans << endl;

    return 0;
}