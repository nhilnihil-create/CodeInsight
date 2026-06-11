#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    ll ans=0;
    rep(i,n+1){
        rep(j,n+1){
            int k=n-i*r-j*g;
            if(k<0)continue;
            if((n-(i*r+j*g))%b==0)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}