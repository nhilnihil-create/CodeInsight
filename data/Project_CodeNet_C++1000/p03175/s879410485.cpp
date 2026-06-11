#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <set>
#include <map>
#include <algorithm>  
#include <cmath>
#include <iomanip>
#define ll long long
using namespace std;
ll n;
ll mod=pow(10,9)+7;
bool visit[100005];
vector<ll>* tree=new vector<ll>[100005];
pair<ll,ll> calc(ll node,ll par)
{
    visit[node]=true;
    ll b=1;ll w=1;
    for(ll i=0;i<tree[node].size();++i)
    {
        if(visit[tree[node][i]]==false)
        {
            pair<ll,ll> ans=calc(tree[node][i],node);
            w=((w%mod)*((ans.first+ans.second)%mod))%mod;
            b=((b%mod)*((ans.first)%mod))%mod;
        }
    }
    return make_pair(w,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    memset(visit,false,sizeof(visit));
    //memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n-1;++i)
    {
        ll a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    pair<ll,ll> okok=calc(1,-1);
    cout<<(okok.first+okok.second)%mod<<endl;
}




































