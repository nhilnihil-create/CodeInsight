#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b, x;
    cin >> a >> b >> x;

    if (x < a + b && x >= a && x - a <= b)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
