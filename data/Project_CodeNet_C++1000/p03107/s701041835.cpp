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
    string s;
    cin >> s;
    int b = 0;
    int r = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            b++;
        }
        else
        {
            r++;
        }
        /* code */
    }
    cout << s.length() - abs(b - r) << endl;

    //    cout << 2 * sum / n << endl;
    return 0;
}