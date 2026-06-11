#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 1e5+5;

ll n , m , a[N] , ans;
map<ll,ll> cnt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i] %= m;
        a[i] += a[i-1];
        a[i] %= m;

        ans += cnt[a[i]];
        if (!a[i]) ans++;


        cnt[a[i]]++;
    }

    cout << ans << "\n";
//

    return 0;
}