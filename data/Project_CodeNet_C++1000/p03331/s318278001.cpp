#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int max = 1 << 30;
    for (int i = 1; i < N; i++)
    {
        int A = i;
        int B = N - A;
        int Ad = 0, Bd = 0;
        while (A != 0)
        {
            Ad += A % 10;
            A /= 10;
        }
        while (B != 0)
        {
            Bd += B % 10;
            B /= 10;
        }
        if (Ad + Bd < max)
        {
            max = Ad + Bd;
        }
    }
    cout << max;
}
