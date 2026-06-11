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

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    vector<ll> A(3);
    for (ll i = 0; i < 3; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cout << A[2] - A[0] << endl;
}