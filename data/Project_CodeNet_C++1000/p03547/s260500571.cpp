#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c1, c2;
    cin >> c1 >> c2;
    if (c1 == c2)
    {
        cout << "=" << endl;
    }
    else if (c1 < c2)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << ">" << endl;
    }
    return 0;
}
