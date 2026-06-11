#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long long int n, p, ans = 1;
    cin >> n >> p;
    long long int i = 1;
    long long int a = pow(2, n);
    long long int min = 2;
    int l = 2;
    if (n == 1)
    {
        cout << p << endl;
        return 0;
    }
    while (pow(i, n) <= p)
    {
        long long int tmp = pow(i, n);
        if (p % tmp == 0)
        {
            ans *= i;
            p /= tmp;
            if (i == 1)
                i++;
        }
        else
        {
            if (i == 3)
                i += 2;
            else if (i > 4)
            {
                i += l;
                l = 6 - l;
            }
            else
                i++;
        }
    }
    cout << ans << endl;
    return 0;
}