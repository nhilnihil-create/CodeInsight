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
    int n = s.length();
    int cnt = 0;
    ll ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            ans += i - cnt;
            cnt++;
        }
    }
    cout << ans << endl;

    return 0;
}