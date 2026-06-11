#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    ll r,d,x; cin>>r>>d>>x;
    ll ans[10];
    rep(i,10){
        ll x2=r*x-d;
        ans[i]=x2;
        x=x2;
    }
    rep(i,10){
        cout<<ans[i]<<endl;
    }
    return 0;
} 