#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;

int main()
{
    ll N,M;
    cin>>N>>M;
    vll P(M);
    vll Y(M);
    for(ll i=0;i<M;i++)
    {
        cin>>P[i]>>Y[i];
        --P[i];
    }
    vvll vals(N);
    for(ll i=0;i<M;i++)vals[P[i]].emplace_back(Y[i]);
    for(ll i=0;i<N;i++)sort(vals[i].begin(),vals[i].end());

    for(ll i=0;i<M;i++)
    {
        ll v=P[i];
        printf("%06d",v+1);

        ll id=lower_bound(vals[v].begin(),vals[v].end(),Y[i])-vals[v].begin();
        printf("%06d\n",id+1);
    }
}