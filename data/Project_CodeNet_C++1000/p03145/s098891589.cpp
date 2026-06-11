#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;

    int s = (a + b + c) / 2;

    int ans = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << ans << endl;
    return 0;
}