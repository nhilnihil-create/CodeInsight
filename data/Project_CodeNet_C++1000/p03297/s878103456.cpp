#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
ll gcd(ll a, ll b)
{
    while (1)
    {
        if (a < b)
            swap(a, b);
        if (!b)
            break;
        a %= b;
    }
    return a;
}
string solve(ll a, ll b, ll c, ll d)
{
    if (a < b || d < b)
    {
        return "No";
    }
    if (c > b)
    {
        return "Yes";
    }
    else
    {
        ll g = gcd(b, d);
        if (b - g + a % g > c)
        {
            return "No";
        }
        else
        {
            return "Yes";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << endl;
    }
}