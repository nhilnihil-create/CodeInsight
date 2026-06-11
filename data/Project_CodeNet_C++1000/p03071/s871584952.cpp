#include <iostream>
using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;
    cout << max (a + b, max(a + a - 1, b + b - 1));
}
