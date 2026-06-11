#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();
    int a[n], b[n];
    a[0] = 0;
    b[n - 1] = 0;
    for (int i = 1; i < len; i++)
    {
        int diff = 0;
        if (s[i - 1] == 'W')
        {
            diff = 1;
        }
        a[i] = a[i - 1] + diff;
    }
    for (int i = len - 2; i >= 0; i--)
    {
        int diff = 0;
        if (s[i + 1] == 'E')
        {
            diff = 1;
        }
        b[i] = b[i + 1] + diff;
    }
    int ans = n + 100;
    REP(i, n)
    {
        ans = min(ans, a[i] + b[i]);
    }
    cout << ans << endl;
}