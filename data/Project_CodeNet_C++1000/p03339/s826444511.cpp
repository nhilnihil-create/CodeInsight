#include <iostream>
#include <string>
#include <vector>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    int e = 0;
    rep(i, 1, n)
    {
        if (s[i] == 'E')
        {
            e++;
        }
    }
    int ans = e;
    //端から移動する人数を数える.
    for (ll i = 1; i < n; i++)
    {
        if (s[i - 1] == 'W')
        {
            e++;
        }
        if (s[i] == 'E')
        {
            e--;
        }

        ans = min(ans, e);
    }
    cout << ans << endl;
    return 0;
}
