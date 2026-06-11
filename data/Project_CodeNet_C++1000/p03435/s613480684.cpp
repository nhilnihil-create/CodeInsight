#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<int> v(9);
    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
    }
    int a = v[0] + v[4] + v[8];
    int b = v[0] + v[5] + v[7];
    int c = v[1] + v[3] + v[8];
    int d = v[1] + v[5] + v[6];
    int e = v[2] + v[3] + v[7];
    int f = v[2] + v[4] + v[6];
    if (a == b && b == c && c == d && d == e && e == f)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}