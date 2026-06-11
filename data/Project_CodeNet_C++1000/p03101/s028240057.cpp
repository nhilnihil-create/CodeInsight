#include <iostream>

using namespace std;

int main()
{
    int R , C , r , c , remaining;
    cin >> R >> C;
    cin >> r >> c;
    remaining = (R - r) * (C - c);
    cout << remaining;
    return 0;
}
