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
    ll A, B;
    cin >> A >> B;

    if (A % 2 == 1 && B % 2 == 1){ 
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}