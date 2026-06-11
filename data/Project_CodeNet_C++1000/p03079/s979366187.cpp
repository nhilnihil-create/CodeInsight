#include <iostream>

using namespace std;

int main()
{
    bool f = false;
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b)
    {
        if (a == c)
        {
            f = true;
        }
    }
    if (f)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}