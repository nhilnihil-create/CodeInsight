#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int X, Y, A;
    cin >> X >> Y;
    A = X;
    long long int count = 0;

    while (A < Y)
    {
        A *= 2;
        count++;
    }

    if (A == Y)
        count++;

    cout << count << endl;

    return 0;
}