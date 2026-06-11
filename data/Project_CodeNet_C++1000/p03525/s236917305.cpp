#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[20],a[30],ans;
ll solve(ll mask){
    ll n=0;
    if(cnt[0]>0)a[n++]=0;
    for(ll i=0;i<12;i++){
        if(cnt[i+1]==0)continue;
        if(cnt[i+1]==2){
            a[n++]=i+1;
            a[n++]=-(i+1);
            continue;
        }

        if( (mask>>i)&1 )a[n++]=i+1;
        else a[n++]=-(i+1);
    }
    sort(a,a+n);
    a[n++]=a[0]+24;
    ll ans=24;
    for(ll i=0;i<n-1;i++)ans=min(ans , a[i+1]-a[i]);
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=0,x;i<n;i++)cin>>x,cnt[x]++;
    cnt[0]++;
    if(cnt[0]>1)return cout<<"0" , 0;
    for(ll i=1;i<=12;i++)if(cnt[i]>2)return cout<<"0" , 0;
    for(ll mask=0;mask<(1ll<<12);mask++)ans=max(ans,solve(mask));
    cout<<ans;
}