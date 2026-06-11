#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    long X, Y;
    cin >> X >> Y;

    long Z = (Y / X);
    long ans = 1;
    while (Z > 1)
    {
        ans++;
        Z /= 2;
    }

    cout << ans << endl;
    return 0;
}