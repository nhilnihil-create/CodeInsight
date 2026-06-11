#include <bits/stdc++.h>

using namespace std;

long double Calc(long long a)
{
    long double Su=0, A=a, B;
    while (a > 0)
    {
        Su += a%10;
        a /= 10;
    }
    B = A/Su;
    return B;
}

int main()
{
    int k;
    long long I=0, a=1, b=0;
    cin >> k;
    while (k > 0)
    {
        k--;
        if (Calc(I+a) <= Calc(I+2*a))
        {
            I += a;
            b++;
            b %= 10;
        }
        else
        {
            while (b < 9)
            {
                b++;
                I += a;
            }
            a *= 10;
            long long A=I;
            b = 0;
            while (A > 0)
            {
                if (A%10 != 9)
                {
                    b = A % 10;
                    break;
                }
                A /= 10;
            }
            I += a;
            A = I;
            b += 10;
            while (A > 0)
            {
                if (A%10 != 9)
                {
                    b = A % 10;
                    break;
                }
                A /= 10;
            }
            if (b >= 10)
            {
                b = 9;
            }
        }
        cout << I << "\n";
    }
    return 0;
}
