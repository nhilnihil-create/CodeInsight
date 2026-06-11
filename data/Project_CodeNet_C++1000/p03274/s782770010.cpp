#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    vector <ll> x(n);
    rep(i,n){
        cin >> x[i];
    }

    ll ans=1000000000000000,ans2;
    rep(i,n-k+1){
        if(x[i]<0){
            if(x[i+k-1]<0){
                ans2=-1*x[i];
                //cout << ans2 << endl;
                ans=min(ans,ans2);
            }
            else{
                ans2=-1*x[i]+x[i+k-1]+min(-1*x[i],x[i+k-1]);
                //cout << ans2 << endl;
                ans=min(ans,ans2);
            }
        }
        else{
            ans2=x[i+k-1];
            ans=min(ans,ans2);
        }
    }

    cout << ans << endl;
    

    return 0;
}