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

int main()
{
    ll A, B;
    cin >> A >> B;

    cout << max({A + B, A - B, A * B}) << endl;
}