#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    for (int c = 0; c <= max(X, Y); ++c)
    {
        int price = 2 * c * C;
        if (X - c > 0)
        {
            price += (X - c) * A;
        }
        if (Y - c > 0)
        {
            price += (Y - c) * B;
        }
        if (ans == 0)
        {
            ans = price;
        }
        else
        {
            ans = min(price, ans);
        }
    }
    cout << ans << endl;
}