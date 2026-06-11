#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <climits>
using namespace std;


int main(void)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;

    for(int i = 1; i <= max(X, Y); i++)
    {
        int x = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i);
        ans = min(ans, x);
    }

    cout << ans << endl;
    
    return 0;
}