#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
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
    string n;
    cin >> n;

    for (ll i = 0; i < n.size(); i++)
    {
        if (n[i] == '1') {
            n[i] = '9';
        } else if (n[i] == '9') {
            n[i] = '1';
        }
    }
    cout << n << endl;

}