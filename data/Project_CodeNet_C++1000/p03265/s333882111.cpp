#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x12=x2-x1;
    int y12=y2-y1;

    cout << x2-y12 << " "
         << y2+x12 << " "
         << x1-y12 << " "
         << y1+x12 << endl;
}