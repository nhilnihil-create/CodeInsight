#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int pa = 0, pb = 0;
    ll value = 0;
    while (pa < X || pb < Y)
    {
        if (pb >= Y)
        {
            value += min(A, 2 * C);
            pa++;
        }
        else if (pa >= X)
        {
            value += min(B, 2 * C);
            pb++;
        }
        else
        {
            value += min(A + B, 2 * C);
            pa++;
            pb++;
        }
    }
    cout << value << endl;
    return 0;
}