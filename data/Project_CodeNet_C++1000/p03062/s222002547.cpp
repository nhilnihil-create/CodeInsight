#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    ll ans,k,m,k2;
    ans=0;
    m=1001001001001;
    k2=0;
    rep(i,n){
        cin >> k;
        if(k<0){
            ++k2;
            m=min(m,k*(-1));
            ans+=k*(-1);
        }
        else{
            m=min(m,k);
            ans+=k;
        }
    }

    if(k2%2==0){
        cout << ans << endl;
    }
    else{
        cout << ans-2*m << endl;
    }
    

    return 0;
}