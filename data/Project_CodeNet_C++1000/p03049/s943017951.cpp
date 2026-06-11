#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, a = 0, b = 0, ab = 0, ans = 0;
    cin >> n;
    repi(i, n, 0)
    {
        string s;
        cin >> s;
        repi(j, s.size(), 1)
        {
            if (s.at(j) == 'B' && s.at(j - 1) == 'A')
                ans++;
        }
        if (s.at(0) == 'B' && s.at(s.size() - 1) == 'A')
            ab++;
        else if (s.at(0) == 'B')
            b++;
        else if (s.at(s.size() - 1) == 'A')
            a++;
    }
    if (ab == 0)
    {
        cout << ans + min(a, b) << endl;
    }
    else if (a + b == 0)
    {
        cout << ans + ab - 1 << endl;
    }
    else
    {
        cout << ans + ab + min(a,b) << endl;
    }
    return 0;
}