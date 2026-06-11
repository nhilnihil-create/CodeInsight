#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,q;
    cin>>n>>m>>q;
    ll l,r;
    while(m--)
    {
        cin>>l>>r;
        v[l].push_back(r);
    }
    for(ll i=1;i<=500;i++)
    {
        sort((v[i].begin()),(v[i].end()));
    }
    //cout<<q<<endl;
    while(q--)
    {
        //cout<<q<<endl;
        cin>>l>>r;
        ll sum=0;
        for(ll i=l;i<=r;i++)
        {
            auto it=upper_bound(v[i].begin(),v[i].end(),r);
            ll num=it-v[i].begin();
            sum+=num;
        }
        cout<<sum<<endl;
    }
	return 0;
}