#include <iostream>

using namespace std;

int main()
{
    int AB,BC,CA;
    int area;
    ios::sync_with_stdio(false);
    cin >> AB >> BC >> CA;
    area = (AB * BC) / 2;
    cout << area << endl;
    return 0;
}