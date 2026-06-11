#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    string y;
    float x, Sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;

        if (y == "JPY")
        {
            Sum += x;
        }

        if (y == "BTC")
        {
            Sum += 380000.0 * x;
        }
    }

    cout << Sum;
}