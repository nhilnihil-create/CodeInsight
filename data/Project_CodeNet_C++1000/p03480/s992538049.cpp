#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define ALL(v) v.begin(), v.end()

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    ll ans = 0;
    ll mi = LLONG_MAX;
    for (ll i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            ll temp = max(i + 1, (ll)(s.size() - i - 1LL));
            if (mi > temp)
            {
                mi = temp;
                ans = temp;
            }
        }
    }
    if (ans == 0)
    {
        ans = s.size();
    }

    cout << ans << endl;
}
