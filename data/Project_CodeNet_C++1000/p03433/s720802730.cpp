#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, x2;
    cin >> x1 >> x2;
    x1 %= 500;
    if (x1 > x2)
        cout << "No";
    else 
        cout << "Yes";
    return 0;
}