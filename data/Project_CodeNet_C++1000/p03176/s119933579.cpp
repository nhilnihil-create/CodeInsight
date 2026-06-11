#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000007
#define MAX 100001
#define INF LLONG_MAX
vector<ll> BIT;
void update(ll i, ll val, ll n){
    for(;i<=n;i+=(i&(-i)))
        BIT[i]=max(BIT[i],val);
}
ll query(ll i){
    ll sum = 0;
    for(;i>0;i-=(i&(-i)))
        sum=max(sum,BIT[i]);
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,tmp;
    cin>>n;
    vector<ll> h,v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        h.pb(tmp);
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.pb(tmp);
    }
    BIT.assign(n+1,0);
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll tmp = query(h[i]-1);
        ans=max(ans,tmp+v[i]);
        update(h[i],tmp+v[i],n);
    }
    cout<<ans<<endl;
    return 0;
}
