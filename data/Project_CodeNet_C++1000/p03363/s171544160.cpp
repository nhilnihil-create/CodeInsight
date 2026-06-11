#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    ll s[n + 1];
    s[0] = 0;

    repi(i, n + 1, 1)
    {
        int a;
        cin >> a;
        s[i] = a + s[i - 1];
    }
    sort(s, s + n + 1);
    ll ans = 0;
    repi(i, n + 1, 0)
    {

        ll cnt = 0;
        ll j = i;
        while(true)
        {
            if (s[i] == s[j])
                cnt++;
            else
            {
                i = j - 1;
                break;
            }
            j ++ ;
            if(j >= n + 1){
                i = j - 1;
                break;
            }
        }
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}