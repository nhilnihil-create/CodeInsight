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
    string s, tmp;
    cin >> s;
    tmp = s;
    reverse(tmp.begin(), tmp.end());
    int ans = 0, i = 0, j = 0, n = s.size();
    while (i < n && j < n)
    {
        if (s[i] == tmp[j])
        {
            i++;
            j++;
        }
        else if (s[i] == 'x')
        {
            i++;
            ans++;
        }
        else if (tmp[j] == 'x')
        {
            j++;
            ans++;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << (ans + max(n - i + 1, n - j + 1)) / 2 << endl;
    return 0;
}