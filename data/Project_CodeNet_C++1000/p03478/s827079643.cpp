#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int t = i;
        int d = 0;
        while (t != 0)
        {
            d += t % 10;
            t /= 10;
        }

        if (A <= d && d <= B)
        {
            sum += i;
        }
    }

    cout << sum;
}