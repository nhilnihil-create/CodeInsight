#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    //vector <ll> c(n),a(n),b(n);
    ll a,b;
    vector <vector <ll>> c(n,vector <ll>(3));
    
    rep(i,n){
        cin >> a >> b;
        c[i][0]=a+b;
        c[i][1]=a;
        c[i][2]=b;
    }

    sort(c.rbegin(),c.rend());
    ll ans=0;
    rep(i,n){
        if(i%2==0){
            ans+=c[i][1];
        }
        else{
            ans-=c[i][2];
        }
    }

    cout << ans << endl;

    

    return 0;
}