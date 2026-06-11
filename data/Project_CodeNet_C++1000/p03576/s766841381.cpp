#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>> coo(n);
    rep(i,n){
        ll x,y; cin>>x>>y;
        coo[i]={x,y};
    }
    sort(coo.begin(),coo.end());
    ll res=-1;
    rep(i,n){
        rep(j,n){
            if(j-i+1<k) continue;
            vector<ll> ys={};
            for(ll l=i; l<=j; l++){
                ys.push_back(coo[l].second);
            }
            sort(ys.begin(),ys.end());
            ll tmp=1e10;
            ll len=ys.size();
            for(ll l=0; l+k-1<len; l++){
                chmin(tmp,ys[l+k-1]-ys[l]);
            }
            if(res==-1) res=(coo[j].first-coo[i].first)*tmp;
            else chmin(res, (coo[j].first-coo[i].first)*tmp);
        }
    }
    cout<<res<<endl;
    return 0;
}