#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, k;
ll a[15];
string d[10005];
bool v[10005];
ll b[15] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool f(string p, string q)
{
    if(p.size() != q.size()) return p.size() < q.size();
    else return p < q;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    for(ll i = 0; i < k; i++)
    {
        scanf("%lld", &a[i]);
    }
    d[0] = "";
    v[0] = true;
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j < k; j++)
        {
            ll t = b[a[j]];
            if(i < t) continue;
            if(!v[i - t]) continue;
            d[i - t].push_back(a[j] + '0');
            if(f(d[i], d[i - t])) d[i] = d[i - t];
            d[i - t].pop_back();
            v[i] = true;
        }
    }
    cout<<d[n]<<endl;
    return 0;
}
