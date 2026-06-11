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
    string s;
    cin >> s;

    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '+'){
            ans += 1;
        } else if (s[i] == '-'){
            ans -= 1;
        }
    }
    cout << ans << endl;
}