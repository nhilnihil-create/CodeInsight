#include <iostream>


using namespace std;

int A, B;
int X, Y, I;

int main()
{
    cin >> A;
    cin >> B;

    X = A + B;
    Y = A - B;
    I = A * B;
    if ((X > Y)&&(X > I))
    {
        cout << X << endl;
    }
    else if (Y > I)
    {
    cout << Y << endl;
    }
    else
    {
    cout << I << endl;
    }
}
