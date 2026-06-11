#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int X;
    int A, B;
    cin >> X;
    if (X == 1)
    {
        cout << "Hello World" << endl;
        return 0;
    }else
    {
        cin >> A >> B;
        cout << A + B << endl;
    }
    
    return 0;
}