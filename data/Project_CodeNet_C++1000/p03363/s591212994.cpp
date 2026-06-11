#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[200005],b[200005];
ll t;
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
    }
    sort(b,b+n+1);
    for(int i=1;i<=n;i++){
        if(b[i]!=b[i-1]){
            ans+=(i-t)*(i-t-1)/2;
            t=i;
        }
    }
    ans+=(n+1-t)*(n-t)/2;
    cout<<ans<<endl;
    
}
