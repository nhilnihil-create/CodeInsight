#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    vv<int> c(3, v<int>(3, 0));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }

    for (int a0 = -500; a0 < 500; a0++)
    {
        int b0 = c[0][0] - a0;
        int b1 = c[1][0] - a0;
        int b2 = c[2][0] - a0;

        int a1_1 = c[0][1] - b0;
        int a2_1 = c[0][2] - b0;
        int a1_2 = c[1][1] - b1;
        int a2_2 = c[1][2] - b1;
        int a1_3 = c[2][1] - b2;
        int a2_3 = c[2][2] - b2;

        if (a1_1 == a1_2 && a1_2 == a1_3 && a1_3 == a1_1 && a2_1 == a2_2 && a2_2 == a2_3 && a2_3 == a2_1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}