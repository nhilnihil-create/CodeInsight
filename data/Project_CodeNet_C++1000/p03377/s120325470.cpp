#include <iostream>

using namespace std;

int main()
{
    int A, B, X, total;
    cin >> A >> B >> X;
    total = A + B;

    if (X>=A && total>=X) {cout << "YES" << endl;}
    else {cout << "NO" << endl;}
}