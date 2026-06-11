#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j, k;
    int H, X, Y;
    cin >> n;
    int val[n][3];
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            cin >> val[i][j];

    for (X = 0; X <= 100; X++)
    {
        for (Y = 0; Y <= 100; Y++)
        {
            for (k = 0; k < n && val[k][2] == 0; k++)
                ;

            H = abs(X - val[k][0]) + abs(Y - val[k][1]) + val[k][2];
            for (i = 0; i < n; i++)
            {
                if (val[i][2] != max((H - abs(X - val[i][0]) - abs(Y - val[i][1])), 0))
                    break;
            }
            if (i == n)
            {
                cout << X << " " << Y << " " << H << endl;
                return 0;
            }
        }
    }

    return 0;
}