#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    string s; cin>>s;
    ll mod=1e9+7;
    map<char,ll> m;
    rep(i,n){
        m[s[i]]++;
    }
    ll res=1;
    rep(i,26){
        res*=m[i+'a']+1;
        res%=mod;
    }
    res--;
    if(res<0) res+=mod;
    cout<<res<<endl;
    return 0;
}