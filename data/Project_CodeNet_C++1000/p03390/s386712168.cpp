#include <bits/stdc++.h>

using namespace std;

int check(int a, int b, int x)
{
    long long ab = (long long) a * b;
    int s, t;
    if (x <= a + 2)
    {
        s = x;
        t = a + 1;
    }
    else if ((a + 1 - x) % 2 == 0)
    {
        s = t = (a + 1 + x) / 2;
    }
    else
    {
        s = (a + 1 + x) / 2;
        t = s + 1;
    }
    return (long long) s * t < ab;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int ans = a - 1;
        int x = 0;
        for (int jump = b / 2 + 1; jump > 0; jump /= 2)
        {
            while (x + jump < b && check(a, b, x + jump))
                x += jump;
        }
        ans += x;
        cout << ans << endl;
    }
    return 0;
}
