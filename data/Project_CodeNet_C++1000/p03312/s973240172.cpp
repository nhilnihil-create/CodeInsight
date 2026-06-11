#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],ans=(1e18);
pair<ll,ll> l[N],r[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0,sl=0,sr=0,cur=0;i<n;i++){
        sr+=a[i];
        while(cur<=i && abs(sl-sr)>=abs(sl+a[cur]-(sr-a[cur])))
            sl+=a[cur],sr-=a[cur],cur++;
        l[i]=make_pair(sl,sr);
    }
    for(ll i=n-1,sl=0,sr=0,cur=n-1;i>=0;i--){
        sl+=a[i];
        while(cur>=i && abs(sl-sr)>=abs(sl-a[cur] - (sr+a[cur])))
            sl-=a[cur],sr+=a[cur],cur--;
        r[i]=make_pair(sl,sr);
    }
    for(ll i=1;i<n-2;i++){
        ll mx = max({l[i].first,l[i].second,r[i+1].first,r[i+1].second});
        ll mn = min({l[i].first,l[i].second,r[i+1].first,r[i+1].second});
        ans = min(ans , mx-mn);
    }
    cout<<ans;
}
