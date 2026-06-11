#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int k,n;
    cin >> n >> k;
    vector <ll> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    ll mi=1001001001001;
    rep(i,n-k+1){
        mi=min(mi,h[i+k-1]-h[i]);
    }

    cout << mi << endl;


    return 0;
}