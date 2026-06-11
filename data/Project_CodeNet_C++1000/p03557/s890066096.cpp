#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n;
ll a[100005],b[100005],c[100005];
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    for(int i=0;i<n;i++){
        ll B=b[i];
        ans+=((lower_bound(a,a+n,B)-a)*(n-(upper_bound(c,c+n,B)-c)));
    }
    cout<<ans<<endl;
    
}
