#include <bits/stdc++.h>
#define S second
#define F first
#define ll long long

using namespace std;

const ll N = 2e5 + 5;

vector<ll> v1, v2, v3, v4;

ll get(ll xx)
{
    ll ret = 0;
    for(auto i:v3)
    {
        ll s = 0, e = v2.size() - 1, mid, best = 0;
        while(s <= e)
        {
            mid = (s + e) / 2;
            if(v2[mid] + i >= xx)
            {
                s = best = mid + 1;
            }
            else e = mid - 1;
        }
        ret += best;
    }
    return ret;
}

int main()
{
    int x, y, z, k;
    ll xx;
    scanf("%d%d%d%d", &x, &y, &z, &k);
    for(int i = 0 ; i < x ; i++)
    {
        scanf("%lld", &xx);
        v1.emplace_back(xx);
    }
    for(int i = 0 ; i < y ; i++)
    {
        scanf("%lld", &xx);
        for(auto j:v1) v2.emplace_back(j + xx);
    }
    sort(v2.rbegin(), v2.rend());
    for(int i = 0 ; i < z ; i++)
    {
        scanf("%lld", &xx);
        v3.emplace_back(xx);
    }
    sort(v3.rbegin(), v3.rend());
    ll s = 1, mid, e = 1e18, best = 1;
    while(s <= e)
    {
        mid = s + (e - s) / 2;
        if(get(mid) >= k)
        {
            best = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    for(auto i:v3)
    {
        for(auto j:v2)
        {
            if(j + i < best) break;
            v4.emplace_back(j + i);
        }
    }
    sort(v4.rbegin(), v4.rend());
    for(int i = 0 ; i < k ; i++) printf("%lld\n", v4[i]);
    return 0;
}
