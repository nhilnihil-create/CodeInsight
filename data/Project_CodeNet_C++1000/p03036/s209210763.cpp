#include <iostream>

using namespace std;

int main(void)
{
    int r, D, x;
    cin >> r >> D >> x;
    for (int count = 0; count < 10; count++)
    {
        x = r * x - D;
        cout << x << endl;
    }
}