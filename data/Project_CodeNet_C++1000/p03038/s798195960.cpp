#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

bool comp(ii a,ii b){
    return a.se>b.se;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m;cin>>n>>m;
    ll a[n];
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];sum+=a[i];
    }
    vector<ii>v(m);
    for(ll i=0;i<m;i++){
        cin>>v[i].fi>>v[i].se;
    }
    sort(a,a+n);
    sort(all(v),comp);
    ll cnt=0;
    bool state=0;
    for(ll i=0;i<m;i++){
        for(ll j=cnt;j<min(cnt+v[i].fi,n);j++){
            if(a[j]<v[i].se){
                sum+=(v[i].se-a[j]);
            }else{
                state=1;break;
            }
        }
        cnt=min(cnt+v[i].fi,n);
        if(state||cnt==n)break;
    }
    cout<<sum<<"\n";
}
