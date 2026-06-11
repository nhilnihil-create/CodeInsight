#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 2e5 + 5;
ll n, arr[N], pre[N], suf[N], mx;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        cin >> arr[i];
        mx = __gcd(mx, arr[i]);
    }
    for(int i = 0;i < n;++i)
    {
        pre[i] = arr[i];
        if(i)               pre[i] = __gcd(pre[i], pre[i - 1]);
    }
    for(int i = n - 1;i >= 0;--i)
    {
        suf[i] = arr[i];
        if(i + 1 < n)       suf[i] = __gcd(suf[i], suf[i + 1]);
    }
    for(int i = 0;i < n;++i)
    {
        ll l = 0, r = 0;
        if(i)           l = pre[i - 1];
        if(i + 1 < n)   r = suf[i + 1];
        mx = max(mx, __gcd(l, r));
    }
    cout << mx;
    return 0;
}
