#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll n;
ll a[200005];
ll sz;
vector<ll> ve, vi;
bool v;
bool vv;

void g(ll p, ll q)
{
    ll now = p;
    while(1)
    {
        if(now == 0)
        {
            vv = true;
            return;
        }
        if(vi.back() == now)
        {
            if(ve.back() == q - 1) vi.pop_back(), ve.pop_back(), now--;
            else
            {
                ve.back()++;
                return;
            }
        }
        else
        {
            ve.push_back(1);
            vi.push_back(now);
            return;
        }
    }
}

bool f(ll p)
{
    ll now = 0;
    vv = false;
    ve.clear(), vi.clear();
    for(ll i = 0; i < n; i++)
    {
        if(a[i] > now)
        {
            now = a[i];
            continue;
        }
        now = a[i];
        while(!vi.empty() && vi.back() > now) ve.pop_back(), vi.pop_back();
        if(!vi.empty() && vi.back() == now) g(now, p);
        else ve.push_back(0), vi.push_back(now), g(now, p);
        if(vv) return false;
    }
    return true;
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if(i > 0 && a[i - 1] >= a[i]) v = true;
    }
    if(!v)
    {
        printf("1\n");
        return 0;
    }
    f(2);
    ll lt = 2, rt = 200000, mid, ans;
    while(lt <= rt)
    {
        mid = (lt + rt) / 2;
        if(f(mid)) ans = mid, rt = mid - 1;
        else lt = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
