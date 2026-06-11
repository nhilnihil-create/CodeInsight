#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;

    for (int i = 1; i < 4; i++)
    {
        if ((a * b * i) % 2 != 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}