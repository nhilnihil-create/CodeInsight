#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1, dy = y2 - y1;
    cout << x2 - dy << " " << y2 + dx << " " << x1 - dy << " " << y1 + dx;
}