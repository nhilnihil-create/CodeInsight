#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,m;
    cin >> n >> m;
    vector <ll> x(m);
    ll xx;
    x[0]=0;
    rep(i,m){
        cin >> x[i];
    }
    sort(x.begin(),x.end());
    vector <ll> sa(m-1);
    rep(i,m-1){
        sa[i]=x[i+1]-x[i];
    }
    sort(sa.begin(),sa.end());
    if(n>=m){
        cout << 0 << endl;
    }
    else{
        ll ans=0;
        rep(i,m-n){
            ans+=sa[i];
        }
        cout << ans << endl;
    }

    

    return 0;
}