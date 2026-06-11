#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;

#define se second
#define fi first
#define mk(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<ll,ll> pll;

int N;
vector<pll> V,ans;
ll child[100010];
ll dp[100010];
map<ll,ll> mp;
ll sum = 0;
bool flag;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        ll d;
        scanf("%lld",&d);
        V.push_back(mk(d,i + 1));
    }

    sort(V.begin(),V.end());

    for(int i = 0; i < V.size(); i++)mp[V[i].fi] = i + 1;
    for(int i = 0; i <= N; i++)child[i] = 1;

    for(int i = V.size() - 1; i > 0; i--)
    {
        ll val = V[i].fi - abs((N - child[i]) - child[i]);
        if(mp[val] != 0 && val < V[i].fi)
        {
            int tmp = mp[val];
            tmp--;
            ans.push_back(mk(V[i].se,V[tmp].se));
            sum += child[i];
            child[tmp] += child[i];
        }
        else flag = true;
    }

    if(V[0].fi != sum || flag)printf("-1\n");
    else
    {
        for(int i = 0; i < ans.size(); i++)
        {
            printf("%lld %lld\n",ans[i].fi,ans[i].se);
        }
    }
    return 0;
}
