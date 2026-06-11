#include <bits/stdc++.h>

using namespace std;

int main()
{
    long N, Sum, a = 0;
    cin >> N;

    for (int i = 1; i <= 100000; i++)
    {
        Sum = i * i;

        if (Sum <= N)
        {
            a++;
        }

        if (Sum > N)
        {
            break;
        }
    }

    cout << a * a;
}