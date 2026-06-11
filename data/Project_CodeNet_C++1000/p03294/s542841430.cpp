#include <iostream>
#include <vector>
#include <algorithm>
int gcd(int x, int y)
{
    return (x % y) ? gcd(y, x % y) : y;
}
int lcm(int x, int y)
{
    return x / gcd(x, y) * y;
}
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}
