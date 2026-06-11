#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    long long a, b, c;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        
        if (a == b || a + 1 == b)
        {
            cout << 2 * a - 2;
        }
        else
        {
            c = sqrt(a * b);
            if (c * c == a * b)
            {
                c--;
            }
            if (c * (c + 1) >= a * b)
            {
                cout << 2 * c - 2;
            }
            else
            {
                cout << 2 * c - 1;
            }
        }
        cout << endl;
    }

    return 0;
}
