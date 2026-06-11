#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    ll N;
    ll pre = 0;
    ll ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        if (temp < pre)
        {
            ans += (pre - temp);
        }

        pre = temp;
    }
    cout << ans + pre << endl;
}