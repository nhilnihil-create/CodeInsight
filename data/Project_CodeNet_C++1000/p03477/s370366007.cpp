#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    int x = x1 + x2;
    int y = y1 + y2;
    if (x > y)
        cout << "Left";
    else if (x < y)
        cout << "Right";
    else 
        cout << "Balanced";
    return 0;
}