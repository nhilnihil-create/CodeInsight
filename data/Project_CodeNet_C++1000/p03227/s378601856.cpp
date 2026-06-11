#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    string S; cin >> S;
    if (S.size() == 2) cout << S << endl;
    else
    {
        reverse(S.begin(), S.end());
        cout << S << endl;
    }
}
