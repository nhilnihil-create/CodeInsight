#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
 
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i]; 
    ll ab = 0, lb = 0, ra = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') ++ab;
        else if (s[i][0] == 'B') ++lb;
        else if (s[i][s[i].size() - 1] == 'A') ++ra;
        for (int k = 0; k < s[i].size() - 1; ++k)
        {
            if (s[i][k] == 'A' && s[i][k + 1] == 'B')
                ++ans;
        }
    }
 
    if (ab == 0)
    {
        ans += min(ra, lb);
    }
    else if (ab > 0 && ra + lb > 0)
    {
        ans += min(ra, lb) + ab;
    }
    else if (ab > 0 && ra + lb == 0)
    {
        ans += ab - 1;
    }
    cout << ans << endl; 
    return 0;
}