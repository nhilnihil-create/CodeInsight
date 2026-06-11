#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    int t,a;
    cin >> n;
    cin >> t >> a;
    vector <ll> h(n);
    ll tt,mi=100000000;
    int ans;
    a*=1000;
    rep(i,n){
        cin >> h[i];
        tt=1000*t-h[i]*6;
        if(abs(tt-a)<mi){
            mi=abs(tt-a);
            ans=i+1;
        }
    }

    cout << ans << endl;

    


    

    return 0;
}