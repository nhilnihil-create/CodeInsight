#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef pair<ll,ll>pi;
#define ff first
#define ss second
vector<pi>v;
#define inf 8e18
ll n,k;
const ll N=100;
bool comp(pi a,pi b)
{
    return a.ff<b.ff;
}
ll x[N+4],y[N+4],a[N+5],b[N+6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        a[i]=x[i],b[i]=y[i];
    }
    ll ans=inf;
    sort(x,x+n);
    sort(y,y+n);
    for(ll lx=0;lx<n;lx++)
        for(ll rx=lx+1;rx<n;rx++)
            for(ll by=0;by<n;by++)
                {
                    for(ll uy=by+1;uy<n;uy++)
                    {
                        ll cnt=0;
                        for(ll i=0;i<n;i++)
                        {
//                            cout<<x[rx]<<" "<<x[lx]<<"   "<<y[uy]<<" "<<y[by]<<endl;
//                            cout<<a[i]<<" "<<b[i]<<endl;
                            if(a[i]<=x[rx]&&a[i]>=x[lx]&&b[i]>=y[by]&&b[i]<=y[uy])cnt++;
                        }
                        if(cnt>=k)
                        {
                            ans=min(ans,(x[rx]-x[lx])*(y[uy]-y[by]));
                        }
                    }
                }
    cout<<ans<<endl;
}
/*
3999999996000000001
*/
