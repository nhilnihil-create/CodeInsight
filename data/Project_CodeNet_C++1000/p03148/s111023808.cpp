#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define go_t int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // order_of_key
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf = 0x3f3f3f3f3f3f3f3fll;//4x10e18
const int maxx = 3000000;
#define PI 3.14159265
int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    pl cake[n];
    vector<ll>type[n+1];
    for(int i=0;i<n;i++){
        cin>>cake[i].fi>>cake[i].se;
        type[cake[i].fi].pb(cake[i].se);
    }
    vector<ll>free;
    vector<ll>uni;
    for(int i=1;i<=n;i++)
    {
        if(type[i].size()==0)continue;
        sort(all(type[i]));
        for(int j=0;j<(type[i].size()-1);j++)
            free.pb(type[i][j]);
        uni.pb(type[i][type[i].size()-1]);
    }
    sort(all(uni));
    sort(all(free));
    reverse(all(uni));
    reverse(all(free));
    for(int i=1;i<free.size();i++)
        free[i]+=free[i-1];
    for(int i=1;i<uni.size();i++)
        uni[i]+=uni[i-1];
    ll ans = 0;
    for(int i=1;i<=min(k,(int)uni.size());i++)
    {
        ll del = uni[i-1];
        int f = min(k-i-1,(int)free.size()-1);
        if(f>=0)del+=free[f];
        //trace3(i,uni[i-1],del);
        ans = max(ans,1LL*i*i + del);
    }
    cout<<ans<<endl;
    return 0;
}
