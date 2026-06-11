#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector <int> ii(n+2,0),ii2(n+2,0);
    int l,r;
    rep(i,m){
        cin >> l >> r;
        ++ii[l];
        --ii[r+1];
    }
    
    int ans=0;
    rep(i,n){
        ii2[i+1]=ii2[i]+ii[i+1];
        if(ii2[i+1]==m){
            ++ans;
        }
    }

    cout << ans << endl;
    

    return 0;
}