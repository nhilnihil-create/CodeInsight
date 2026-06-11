#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll x;
ll n = 18;
ll now;
vector<ll> vs, ve, vl;
ll base;

int main()
{
    scanf("%lld", &x);
    x--;
    for(base = 0; ; base++)
    {
        if((1 << (base + 1)) - 1 > x)
        {
            break;
        }
    }
    now = (1 << (base)) - 1;
    for(ll i = 1; i <= base; i++)
    {
        vs.push_back(i), ve.push_back(i + 1), vl.push_back(0);
        vs.push_back(i), ve.push_back(i + 1), vl.push_back((1 << (i - 1)));
    }
    for(ll i = base; i >= 1; i--)
    {
        if(x - now >= (1 << (i - 1)))
        {
            vs.push_back(i);
            ve.push_back(base + 1);
            vl.push_back(now + 1);
            now += (1 << (i - 1));
        }
    }
    printf("%lld %lld\n", base + 1, (ll)vs.size());
    for(ll i = 0; i < vs.size(); i++)
    {
        printf("%lld %lld %lld\n", vs[i], ve[i], vl[i]);
    }
    return 0;
}
