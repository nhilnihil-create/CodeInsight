#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debug3(x, y,z) cout << #x << " = " << x << "   " << #y << " = " << y << " "<<#z<<" = "<<z<<"\n";
#define debugarray(arr,n) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , \n";}


vector<ll>segtree,dp;
void update(ll index,ll start,ll end,ll i,ll newvalue)
{
    //outside
    if(i<start || i>end) return ;
    if(start==end) {
        dp[start]=segtree[index]=newvalue;
        return ;
    }
    ll mid = (start+end)/2;
    update(2*index+1,start,mid,i,newvalue);
    update(2*index+2,mid+1,end,i,newvalue);
    segtree[index]=max(segtree[2*index+1],segtree[2*index+2]);
}
ll query(ll index,ll start,ll end,ll l ,ll r)
{
    //outside
    if(r<start || l>end) return LLONG_MIN;
    //inside 
    if(start>=l && end<=r) return segtree[index];
    ll mid = (start+end)/2;
    ll left = query(2*index+1,start,mid,l,r);
    ll right = query(2*index+2,mid+1,end,l,r);
    return max(left,right);
}


int main()
{

    ll n;
    cin>>n;
    vector<ll>h(n),a(n);
    for(auto &it:h)cin>>it;
    for(auto &it:a) cin>>it;
    dp = vector<ll>(n+1);
    segtree= vector<ll>(4*n+4);

    for(ll i=0;i<n;i++){
        ll mx = query(0,0,n,0,h[i]-1);
        update(0,0,n,h[i],mx+a[i]);
    }
    ll ans = query(0,0,n,1,n);
    cout<<ans;

}