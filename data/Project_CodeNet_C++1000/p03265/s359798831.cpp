#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int vecx = x2 - x1,vecy = y2 - y1;

    cout << x2 - vecy <<  " ";
    cout << y2 + vecx <<  " ";
    cout << x1 - vecy <<  " ";
    cout << y1 + vecx << endl;
}