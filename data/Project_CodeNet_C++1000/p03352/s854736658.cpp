#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int x;
    cin>>x;
    ll ans=0;
    ll maxv=1;
    for(int i=1;i<x;i++){
        for(int j=2;j<11;j++){
            ans=pow(i,j);
            if(x>=ans) maxv=max(maxv,ans);
            //cout<<ans<<" "<<i<<" "<<j<<"\n";}

            else break;
        }
    }
    cout<<maxv<<"\n";
    return 0;
}