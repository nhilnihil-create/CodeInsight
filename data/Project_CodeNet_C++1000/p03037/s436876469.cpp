#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define pb push_back
int main()
{
    ll n, m;

    cin>>n>>m;

    ll  mx=-1000,mn=1e7;

    for(ll i=0;i<m;i++)
    {
        ll a,b;

        cin>>a>>b;

        mx=max(a,mx);

        mn=min(b,mn);
    }

  	if(mn-mx<0)cout<<0<<endl;

  	else cout<<mn-mx + 1;

}
