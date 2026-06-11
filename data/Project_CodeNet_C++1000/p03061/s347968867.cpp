#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll pre[n];
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = __gcd(a[i],pre[i-1]);
    }
    ll suf[n];
    suf[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i] = __gcd(a[i],suf[i+1]);
    }
    ll ans = 1;
    for(int i=0;i<n;i++){
        ll x,y;
        if(i-1>=0) x = pre[i-1];
        else x = 0;
        if(i+1<n) y = suf[i+1];
        else y = 0;
        ans = max(ans,__gcd(x,y));
    }
    cout<<ans<<"\n";

    return 0;

}


