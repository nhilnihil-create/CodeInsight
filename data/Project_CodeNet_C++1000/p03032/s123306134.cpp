#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll n,k; cin>>n>>k;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    ll res=0;
    for(ll a=0; a<=k; a++){
        for(ll b=0; b<=k; b++){
            if(a+b>k || a+b>n) continue;
            ll x=k-a-b;
            vector<ll> memo={};
            rep(i,a) memo.push_back(v[i]);
            rep(i,b) memo.push_back(v[n-1-i]);
            sort(memo.begin(), memo.end());
            ll tmp=0;
            rep(i, a+b){
                if(i<x && memo[i]<0) continue;
                tmp+=memo[i];
            }
            chmax(res, tmp);
        }
    }
    cout<<res<<endl;
    return 0;
}