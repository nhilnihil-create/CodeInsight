#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

long long a, b, c, d;

void solve()
{
    cin >> a >> b >> c >> d;
    if (d < b)
    {
        cout << "No\n";
        return;
    }
    if (a < b)
    {
        cout << "No\n";
        return;
    }
    long long g = __gcd(b, d);
    long long k = (a - c) / g;
    if ((a - c) % g == 0) k--;
    if (a - k * g < b) cout << "No\n";
    else cout << "Yes\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
