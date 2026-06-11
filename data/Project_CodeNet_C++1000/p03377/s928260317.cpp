#include <iostream>

using namespace std;

int main()
{
    int A, B, X;
    cin >> A;
    cin >> B;
    cin >> X;
    if((X>=A)&(A+B)>=X)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
