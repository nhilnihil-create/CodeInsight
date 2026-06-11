#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int max = (a > b) ? a : b;
    int min = (a > b) ? b : a;
    while (max % min)
    {
        int tmp = max % min;
        max = min;
        min = tmp;
    }
    return min;
}
int main()
{
    int n, x, ans(0);
    cin >> n >> x;
    int city[n];
    for (int &i : city)
    {
        cin >> i;
        i -= x;
    }
    if (n > 1)
    {
        ans = gcd(abs(city[0]), abs(city[1]));
        for (int i = 2; i < n; ++i)
        {
            ans = gcd(abs(ans), abs(city[i]));
        }
    }
    else if (n == 1)
        ans = abs(city[0]);
    cout << ans << endl;
}