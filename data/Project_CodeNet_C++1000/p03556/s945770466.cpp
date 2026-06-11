#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    ll N;
    cin >> N;

    ll mx = 0;
    for (ll i = 1; i * i < 1e9; i++)
    {
        if (i * i <= N){ 
            mx = i * i;
        }
    }
    cout << mx << endl;
}