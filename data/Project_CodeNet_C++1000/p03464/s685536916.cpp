#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n;cin>>n;
    ll a[100010];
    rep(i,0,n)cin>>a[i];
    if(a[n-1]!=2){cout<<-1<<endl;return 0;}
    ll l=2,r=2;
    for(ll i=n-1;i>=0;i--){
        l=(l+a[i]-1)/a[i]*a[i];
        r=r/a[i]*a[i]+a[i]-1;
        if(l>r){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<l<<" "<<r<<endl;
}

    







