#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    ll f[n][10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >>f[i][j];
        }
    }
    vector<vector<ll>>p(n,vector<ll>(11));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >>p[i][j];
        }
    }
    ll ans=-INF;
    for (int i = 1; i < (1LL<<10) ; ++i) {
        ll now=0;vector<ll>cnt(n,0);
        for (int j = 0; j < 10; ++j) {
            if(i&(1<<j)){
                for (int k = 0; k < n; ++k) {
                    if(f[k][j]==1){
                        cnt[k]++;
                    }
                }
            }
        }
        for (int l = 0; l < n; ++l) {
            now+=p[l][cnt[l]];
        }
        //if(i==512){
          //  cout <<cnt[0]<<" "<<cnt[1]<<endl;
            //cout <<p[0][0]<<" "<<p[1][1]<<endl;
        //}
        ans=max(ans,now);
    }
    cout <<ans <<endl;
    return 0;
}