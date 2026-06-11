
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

int main()
{
    fastread();

    ll n,m;

    cin>>n>>m;

    ll ara[n+1];


    for(ll i=0;i<n;i++)
    {
        cin>>ara[i];
    }




    sort(ara, ara+n);

    vector<pair<ll,ll>>v;

    for(ll i=0;i<m;i++)
    {
        ll v1,v2;

        cin>>v1>>v2;

        v.eb(v2,v1);

    }


    sort(v.rbegin(),v.rend());


    vector<ll>p;
    ll j=0;
    for(ll i=0;i<m && j<n;i++)
    {
        ll ta=v[i].fi;

        ll va=v[i].se;
j+=va;
        while(va--)p.eb(ta);

    }

   // for(auto x:p)cout<<x<<" ";cout<<endl;

    ll sum=0;
    j=0;
    ll len=p.size();
    for(ll i=0;i<n;i++)
    {
    if(len>j)
        {
           if(p[j]>ara[i])
            {
                sum+=p[j];
                j++;
            }else {

                sum+=ara[i];
            }

        }else sum+=ara[i];
    }

    cout<<sum<<endl;




}
