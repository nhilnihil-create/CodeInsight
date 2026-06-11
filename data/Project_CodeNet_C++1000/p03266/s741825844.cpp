#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 2e5 + 5;
ll n, k, ans, frq[N];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        ++frq[i % k];
    for(int i = 1;i <= n;++i)
    {
        ll rem = k - i;
        rem %= k;
        rem += k;
        rem %= k;
        if((rem * 2) % k == 0)
            ans += frq[rem] * frq[rem];
    }
    cout << ans;
    return 0;
}
