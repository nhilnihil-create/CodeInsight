#include <bits/stdc++.h>
using namespace std;

void add357(vector<int> &array, int n, int a, int b, int c)
{
    if (a <= n)
    {
        array.push_back(a);
    }
    if (b <= n)
        array.push_back(b);
    if (c <= n)
        array.push_back(c);
    if (a <= n / 10)
        add357(array, n, a * 10 + 3, a * 10 + 5, a * 10 + 7);
    if (b <= n / 10)
        add357(array, n, b * 10 + 3, b * 10 + 5, b * 10 + 7);
    if (c <= n / 10)
        add357(array, n, c * 10 + 3, c * 10 + 5, c * 10 + 7);
}
int main()
{
    vector<int> number;
    int n, ans(0);
    cin >> n;
    add357(number, n, 3, 5, 7);
    int tmp, a3, a5, a7;
    for (int i = 0; i < number.size(); ++i)
    {
        tmp = number[i];
        a3 = 0, a5 = 0, a7 = 0;
        while (tmp)
        {
            if (tmp % 10 == 3)
                a3++;
            else if (tmp % 10 == 5)
                a5++;
            else if (tmp % 10 == 7)
                a7++;
            tmp /= 10;
        }
        if (a3 && a5 && a7)
        {
            ans++;
        }
    }
    cout << ans << endl;
}