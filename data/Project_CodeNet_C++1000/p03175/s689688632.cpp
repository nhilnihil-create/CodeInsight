#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
struct nodS
{
    long long dpb, dpw;
    vector<int> v;
};
int n,i,x,y;
nodS nod[100005];
void dfs(int p, int par)
{
    nod[p].dpw=nod[p].dpb=1;

    for(int it : nod[p].v)
    {
        if(it==par)
            continue;

        dfs(it, p);

        nod[p].dpw*=(nod[it].dpb + nod[it].dpw)%mod;
        nod[p].dpw%=mod;

        nod[p].dpb*=nod[it].dpw%mod;
        nod[p].dpb%=mod;
    }
}
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].v.push_back(y);
        nod[y].v.push_back(x);
    }

    dfs(1, 0);

    cout<<(nod[1].dpw+nod[1].dpb)%mod;
    return 0;
}
