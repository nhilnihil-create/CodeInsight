#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Imposter ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[m];
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m);
    vector<ll>vb;
    ll ans=0;
    if(n<m)
    {
        for(int i=0;i<m-1;i++)
            vb.push_back(a[i+1]-a[i]);
        sort(vb.begin(),vb.end());
        for(int i=0;i<m-n;i++)
            ans+=vb[i];
    }
    cout<<ans<<endl;
}
int main()
{
    Imposter

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
