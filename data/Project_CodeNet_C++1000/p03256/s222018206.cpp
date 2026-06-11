#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll n, m;
string s;
ll a[200005];
vector<ll> ve[200005];
ll A[200005], B[200005];
bool v[200005];
bool vv[200005];
queue<ll> qu;

int main()
{
    scanf("%lld%lld", &n, &m);
    cin>>s;
    for(ll i = 0; i < n; i++)
    {
        a[i + 1] = (s[i] == 'A');
    }
    for(ll i = 0; i < m; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j < ve[i].size(); j++)
        {
            if(a[ve[i][j]] == 1) A[i]++;
            else B[i]++;
        }
        if(A[i] == 0 || B[i] == 0) v[i] = true, qu.push(i);
    }
    while(!qu.empty())
    {
        ll t = qu.front();
        qu.pop();
        for(ll j = 0; j < ve[t].size(); j++)
        {
            if(v[ve[t][j]]) continue;
            if(a[t] == 1) A[ve[t][j]]--;
            else B[ve[t][j]]--;
            if(A[ve[t][j]] == 0 || B[ve[t][j]] == 0)
            {
                if(!v[ve[t][j]]) v[ve[t][j]] = true, qu.push(ve[t][j]);
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        if(!v[i])
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
