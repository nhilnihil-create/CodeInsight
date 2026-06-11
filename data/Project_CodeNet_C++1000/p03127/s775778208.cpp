#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#define ll long long
#define pi (acos(-1))
using namespace std;
int main()
{
        ll n;cin>>n;
    ll t;
    ll ans = 0;
    for (ll i = 0; i != n; ++i)
    {
        cin >> t;
        ans = gcd(ans, t);
    }
    std::cout << ans << std::endl;
    return 0;
}
