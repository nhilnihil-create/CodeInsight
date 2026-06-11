#include <iostream>
using namespace std;

int main() {
    int Oneday = 24;

    int a;
    cin >> a;
    if (a < 1)
    {
        return -1;
    }
    if (a > 23)
    {
        return -1;
    }

    int b;
    b = Oneday - a;
    cout << Oneday + b << endl;
}