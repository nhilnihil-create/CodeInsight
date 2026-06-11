#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 2e5+5;

ll pre[N] , suf[N] , n , a[N] , ans=0;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        pre[i] = __gcd(pre[i-1] , a[i]);
    }

    ans = pre[n];
    for(int i=n; i>0; i--)
    {
        suf[i] = __gcd(suf[i+1] , a[i]);
    }

    for(int i=1; i<=n; i++)
    {
        ll tmp = __gcd(suf[i+1] , pre[i-1]);
        ans = max(ans , tmp);
    }
    cout << ans << '\n';
//
    return 0;
}