#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll num;
    cin >> num;

    // vector<ll> transport(5);
    ll x;
    ll temp;
    ll maximum = -1;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        if (num % x == 0)
        {
            temp = num / x;
        }
        else
        {
            temp = num / x + 1;
        }
        maximum = max(maximum, temp);
    }
    ll ans = maximum + 4;
    cout << ans << endl;
    return (0);
}