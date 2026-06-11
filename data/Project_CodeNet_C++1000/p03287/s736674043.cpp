#include <bits/stdc++.h>
#define S second
#define F first
#define ll long long

using namespace std;

const int N = 1e5 + 5, bSize = 505;

ll arr[N];
map<ll, ll> cnt;

ll ans = 0;

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    cnt[0] = 1;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%lld", arr + i);
        if(i) arr[i] += arr[i - 1];
    }
    for(int i = 0 ; i < n ; i++)
    {
        ans += cnt[arr[i] % m];
        cnt[arr[i] % m]++;
    }
    printf("%lld\n", ans);
}
