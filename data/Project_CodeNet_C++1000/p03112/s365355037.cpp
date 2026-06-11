#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll a,b,q; cin>>a>>b>>q;
    vector<ll> s(a), t(b);
    rep(i,a) cin>>s[i];
    rep(i,b) cin>>t[i];

    rep(i,q){
        ll x; cin>>x;
        auto itr1=lower_bound(s.begin(), s.end(), x);
        ll index1=itr1-s.begin();

        auto itr2=lower_bound(t.begin(), t.end(), x);
        ll index2=itr2-t.begin();

        vector<ll> tmp(4, 1e12);
        if(index1>0) tmp[0]=x-s[index1-1];
        if(index1<a) tmp[1]=s[index1]-x;

        if(index2>0) tmp[2]=x-t[index2-1];
        if(index2<b) tmp[3]=t[index2]-x;

        ll res=max(tmp[0], tmp[2]);
        chmin(res, max(tmp[1], tmp[3]));
        chmin(res, tmp[0] + 2 * tmp[3]);
        chmin(res, tmp[2] + 2 * tmp[1]);
        chmin(res, 2 * tmp[0] + tmp[3]);
        chmin(res, 2 * tmp[2] + tmp[1]);

        cout<<res<<endl;
    }
    return 0;
}