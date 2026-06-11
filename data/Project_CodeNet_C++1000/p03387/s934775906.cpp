#include <bits/stdc++.h>
using namespace std;

int x[3];

int main()
{
    cin >> x[0] >> x[1] >> x[2];
    sort(x, x + 3);

    int cnt = 0;
    
    int a = (x[2] - x[1]) / 2;
    cnt += a;

    int b = (x[2] - x[1]) % 2;

    if (b % 2 != 0)
    {
        x[1]++;
        x[0]++;
        cnt++;
    }

    if ((x[2] - x[0]) % 2 == 0)
    {
        cnt += (x[2] - x[0]) / 2;
    }
    else
    {
        cnt++;
        cnt += (x[2] + 1 - x[0]) / 2;
    }
    cout << cnt << endl;

    return 0;
}
