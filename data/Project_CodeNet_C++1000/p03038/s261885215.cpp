#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

ll a[100100];
P p[100100];

int main(void){
    ll n,m,b,c;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        cin>>b>>c;
        p[i]=P(c,b);
    }
    sort(a,a+n);
    sort(p,p+m);
    reverse(p,p+m);
    ll k=0;
    for(int i=0;i<n;i++){
        if(a[i]>=p[k].first) break;
        a[i]=p[k].first;
        p[k].second--;
        if(p[k].second==0) k++;
        if(k==m) break;
    }
    ll ans=0;
    for(int i=0;i<n;i++) ans+=a[i];
    cout<<ans<<endl;
}