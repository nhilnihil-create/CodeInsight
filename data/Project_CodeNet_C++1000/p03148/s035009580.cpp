#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define F first
#define S second
#define PLL pair<ll, ll>

using namespace std;

typedef long long ll;

ll n, k;
ll b[100005];
pair<ll, ll> a[100005];
priority_queue<PLL, vector<PLL>, greater<PLL> > pq;
priority_queue<PLL> pq2;
ll now;
ll ans;
ll cnt;

int main()
{
    scanf("%lld%lld", &n, &k);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i].S, &a[i].F);
    }
    sort(a, a + n, greater<pair<ll, ll> >());
    for(ll i = 0; i < k; i++)
    {
        now += a[i].F;
        b[a[i].S]++;
        if(b[a[i].S] == 1) cnt++;
        pq.push(a[i]);
    }
    for(ll i = k; i < n; i++)
    {
        pq2.push(a[i]);
    }
    ans = now + cnt * cnt;
    while(!pq.empty() && !pq2.empty())
    {
        PLL t1 = pq.top();
        PLL t2 = pq2.top();
        if(b[t1.S] <= 1)
        {
            pq.pop();
            continue;
        }
        if(b[t2.S] > 0)
        {
            pq2.pop();
            continue;
        }
        pq.pop(), pq2.pop();
        b[t1.S]--;
        b[t2.S]++;
        now -= t1.F, now += t2.F;
        cnt++;
        ans = max(ans, now + cnt * cnt);
    }
    printf("%lld\n", ans);
    return 0;
}
