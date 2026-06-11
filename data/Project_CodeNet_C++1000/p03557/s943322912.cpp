#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(){
    int n;cin>>n;
    ll a[n],b[n],c[n];

    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    
    ll ans=0;
    
    ll bb[n],bbs[n+1];
    rep(i,n)bb[i]=n - (lower_bound(c, c + n, b[i]+1) - c);
    
    bbs[0]=0;
    rep(i,n+1)bbs[i+1]=bbs[i]+bb[i];
    
    rep(i,n){
        int tmp = lower_bound(b, b + n, a[i]+1) - b;
            if(tmp<=n)ans += bbs[n]-bbs[tmp];
        }
    
    cout<<ans<<endl;
    return 0;
}