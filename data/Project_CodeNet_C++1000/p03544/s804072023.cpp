#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    ll count = 1;
    ll Lb = 2, La = 1;
    ll ans = 0;
    while (count != n)
    {
        ans = Lb + La;
        Lb = La;
        La = ans;
        count++;
    }
    cout << ans << endl;
}
