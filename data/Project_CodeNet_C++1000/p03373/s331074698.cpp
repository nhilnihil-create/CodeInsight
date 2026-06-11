#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;
    int min = INT_MAX;
    for (int i = 0; i <= max(X,Y); i++)
    {
        int a = A;
        int price = i * C * 2;
        if (i<X) price += (X - i)*A;
        if (i<Y) price += (Y - i)*B;

        if (min > price) min = price;
    }
    cout << min << endl;
}