#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    vector<vector<int>> l(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> l[i][j];
    bool v = true;
    int x, y, z;
    x = l[0][1] - l[0][0], y = l[1][1] - l[1][0], z = l[2][1] - l[2][0];
    if (x != y || y != z || z != x)
        v = false;
    x = l[0][1] - l[0][2], y = l[1][1] - l[1][2], z = l[2][1] - l[2][2];
    if (x != y || y != z || z != x)
        v = false;
    x = l[1][0] - l[0][0], y = l[1][1] - l[0][1], z = l[1][2] - l[0][2];
    if (x != y || y != z || z != x)
        v = false;
    x = l[1][0] - l[2][0], y = l[1][1] - l[2][1], z = l[1][2] - l[2][2];
    if (x != y || y != z || z != x)
        v = false;
    cout << (v ? "Yes" : "No");
}