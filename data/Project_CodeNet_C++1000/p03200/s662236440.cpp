#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;

int main(){
    cin>>s;
    ll cnt=0;
    ll ans=0;
    rep(i,s.size()){
        if(s[i]=='B') cnt++;
        else ans+=cnt;
    }
    cout<<ans<<"\n";
    return 0;
}