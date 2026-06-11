#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    int b = a[2] * 2 - a[1] - a[0];
    if (b % 2 == 0)
    {
        cout << b / 2 << endl;
    }
    else
    {
        cout << b / 2 + 2 << endl;
    }

    return 0;
}