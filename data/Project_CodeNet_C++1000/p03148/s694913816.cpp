#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>> sushi(n); // sushi[i] = {美味しさ, 種類}
    vector<pair<ll,ll>> reserve;
    rep(i,n) cin>>sushi[i].second>>sushi[i].first;
    sort(sushi.begin(), sushi.end(), greater<pair<ll,ll>>());
    map<ll,ll> m;
    vector<ll> f, s;
    rep(i,n){
        if(m[sushi[i].second]==0){
            m[sushi[i].second]=1;
            f.push_back(sushi[i].first);
        }else{
            s.push_back(sushi[i].first);
        }
    }

    sort(f.begin(), f.end(), greater<ll>());
    sort(s.begin(), s.end(), greater<ll>());

    vector<ll> F(f.size()+1), S(s.size()+1);
    rep(i, f.size()){
        F[i+1]=F[i]+f[i];
    }
    rep(i, s.size()){
        S[i+1]=S[i]+s[i];
    }

    ll res=0;

    for(ll i=0; i<=k; i++){
        if(i>f.size() || (k-i)>s.size()) continue;
        chmax(res, F[i]+S[k-i]+i*i);
    }
    cout<<res<<endl;

    return 0;
}