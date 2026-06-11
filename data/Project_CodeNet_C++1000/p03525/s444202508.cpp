#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <int> d(n+1);
    rep(i,n){
        cin >> d[i];
    }
    d[n]=0;
    sort(d.begin(),d.end());
    rep(i,n+1){
        if((i%2)==1){
            d[i]=24-d[i];
        }
    }

    sort(d.begin(),d.end());
    int ans=25;
    rep(i,n){
        if((d[i+1]-d[i])<ans){
            ans=d[i+1]-d[i];
        }
    }

    ans=min(ans,24-d[n]);
    cout << ans << endl;
    

    return 0;
}