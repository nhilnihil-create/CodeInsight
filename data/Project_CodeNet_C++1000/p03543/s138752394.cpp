#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X, Y, Z;
    cin >> N;
    X = 98;
    Y = 36;
    Z = N;
    while (N > 0)
    {
        Z = N % 10;
        if (Z == Y)
        {
            X = Z;
            N /= 10;
            Z = N % 10;
            if (X == Y && Y == Z)
            {
                cout << "Yes" << endl;

                break;
            }
            else
            {
                cout << "No" << endl;
                break;
            }
        }
        else if (N < 10)
        {
            cout << "No" << endl;
        }
        Y = Z;
        N /= 10;
    }
}