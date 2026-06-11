#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n;
    cin >>a;
    cin >>b;
    c=(a * n);
    cout << fmin(c, b);
    return 0;
}
