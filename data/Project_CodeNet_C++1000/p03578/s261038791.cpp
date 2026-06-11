#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll n,m;
vector<ll> d(200100),t(200100);
map<ll,ll> dict;

int main(){
    bool flag=true;
    cin>>n;
    rep(i,0,n){
        cin>>d[i];
        dict[d[i]]++;
    }
    cin>>m;
    rep(i,0,m){
        cin>>t[i];
        dict[t[i]]--;
        if(dict[t[i]]<0) flag=false;
    }

    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    return 0;
}
