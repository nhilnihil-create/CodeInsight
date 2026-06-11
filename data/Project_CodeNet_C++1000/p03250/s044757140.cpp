#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int max;

    cin >> a >> b >> c;

    if(a >= b && a >= c) {
        max = a;
    } else if(b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

    cout << (max*9)+a+b+c << endl;

    return 0;
}