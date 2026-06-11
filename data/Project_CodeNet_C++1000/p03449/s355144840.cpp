#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    int pre[n+1];
    int suf[n+2];
    pre[0]=0;
    for(int i=1 ; i<=n ; i++) {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1 ; i<=n ; i++) {
        cin>>b[i];
    }
    suf[n+1]=0;
    for(int i=n ; i>=1 ; i--) {
        suf[i]=suf[i+1]+b[i];
    }
    int ans=0;
    for(int i=1 ; i<=n ; i++) {
        ans=max(ans,pre[i]+suf[i]);
    }
    cout<<ans;
}
