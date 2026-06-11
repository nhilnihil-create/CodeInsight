#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
#include <map>
#include <set>

const int INT_INF = 1e9;
const long long LONG_INF = 1e18;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long int l = 0, r = s.length() - 1;
    long long int ans = 0;
    while (l < r)
    {
        if (s[l] == 'W')
        {
            l++;
        }
        else if (s[r] == 'B')
        {
            r--;
        }
        else
        {
            ans += r - l;
            l++;
            r--;
        }
    }

    cout << ans << endl;
    return 0;
}