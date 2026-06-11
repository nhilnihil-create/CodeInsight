#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<ll> x(n), y(n);
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        cin>>x[i]>>y[i];
        p[i]={x[i], y[i]};
    }
    sort(p.begin(), p.end());
    ll res=5*1e18;
    for(ll left=0; left<n; left++){
        for(ll right=left; right<n; right++){
            if(right-left+1<k) continue;
            ll width=p[right].first-p[left].first;
            vector<ll> Y;
            for(ll i=left; i<=right; i++) Y.push_back(p[i].second);
            sort(Y.begin(), Y.end());
            ll tmp=1e15;
            for(ll i=0; i+k<=Y.size(); i++){
                chmin(tmp, Y[i+k-1]-Y[i]);
            }
            chmin(res, width*tmp);
        }
    }
    cout<<res<<endl;
    return 0;
}