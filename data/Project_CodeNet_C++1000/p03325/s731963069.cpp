#include <iostream>
using namespace std;
#define int long long int
int twos(int a)
{
    int ans = 0;
    ;
    while (a % 2 == 0)
    {
        ans++;
        a /= 2;
    }
    return ans;
}
signed main()
{
    int n, a, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ans += twos(a);
    }
    cout << ans;
    return 0;
}