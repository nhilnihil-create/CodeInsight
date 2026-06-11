#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k, q;
ll a[2005];
vector<ll> ve, ans;
ll ans2 = 4e18;

int main()
{
    scanf("%lld%lld%lld", &n, &k, &q);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(ll i = 0; i < n; i++)
    {
        a[n] = -4e18;
        ans.clear();
        for(ll j = 0; j <= n; j++)
        {
            if(a[i] > a[j])
            {
                sort(ve.begin(), ve.end());
                for(ll l = 0; l < (ll)ve.size() - k + 1; l++)
                {
                    ans.push_back(ve[l]);
                }
                ve.clear();
            }
            else
            {
                ve.push_back(a[j]);
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() >= q) ans2 = min(ans2, ans[q - 1] - a[i]);
    }
    cout<<ans2<<endl;
    return 0;
}
