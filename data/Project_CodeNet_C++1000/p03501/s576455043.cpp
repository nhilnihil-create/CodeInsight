#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans;

    if (n * a > b)
    {
        ans = b;
    }
    else
    {
        ans = n * a;
    }
    cout << ans << endl;
    return 0;
}