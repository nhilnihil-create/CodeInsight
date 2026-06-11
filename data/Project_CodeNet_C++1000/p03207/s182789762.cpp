#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    ll ans=0,ma=0,p;
    rep(i,n){
        cin >> p;
        ma=max(ma,p);
        ans+=p;
    }

    cout << ans-ma/2 << endl;
    
    

    return 0;
}