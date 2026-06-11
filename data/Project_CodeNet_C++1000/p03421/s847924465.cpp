#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll n, a, b, cnt;
vector<ll> ve[300005], ans, ve2;

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    cnt = n;
    if(n > a * b || n < a + b - 1)
    {
        printf("-1\n");
        return 0;
    }
    for(ll i = 1; i <= a; i++)
    {
        ve[i].push_back(i * b);
        cnt--;
    }
    for(ll i = 1; i <= a; i++)
    {
        for(ll j = 0; j < min(cnt, b - 1); j++)
        {
            ve[i].push_back(ve[i].back() - 1);
        }
        cnt -= min(cnt, b - 1);
    }
    for(ll i = 1; i <= a; i++) for(ll j = 0; j < ve[i].size(); j++) ans.push_back(ve[i][j]), ve2.push_back(ve[i][j]);
    sort(ve2.begin(), ve2.end());
    for(ll i = 0; i < ans.size(); i++)
    {
        printf("%lld ", (ll)(lower_bound(ve2.begin(), ve2.end(), ans[i]) - ve2.begin()) + 1);
    }
    return 0;
}
