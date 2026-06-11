#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int X,Y,Z,K;
    cin>>X>>Y>>Z>>K;
    vector<ll> A(X),B(Y),C(Z);
    rep(i,X)cin>>A.at(i);
    rep(i,Y)cin>>B.at(i);
    rep(i,Z)cin>>C.at(i);
    sort(A.begin(),A.end());
    vector<ll> BC(Y*Z);
    rep(i,Y*Z){
        BC.at(i)=B.at(i/Z)+C.at(i%Z);
    }
    sort(BC.begin(),BC.end());
    ll r=-1,l=A.back()+BC.back()+1;
    while(l-r>1){
        ll m=(r+l)/2;
        ll count=0;
        rep(i,X){
            count+=BC.end()-lower_bound(BC.begin(),BC.end(),m-A.at(i));
        }
        if(count<=K){l=m;}
        else{r=m;}
    }
    vector<ll> ans(0);
    reverse(A.begin(),A.end());
    reverse(BC.begin(),BC.end());
    rep(i,X){
        rep(j,Y*Z){
            if(A.at(i)+BC.at(j)>=l){ans.pb(A.at(i)+BC.at(j));}
            else{break;}
        }
    }
    sort(ans.rbegin(),ans.rend());
    rep(i,sz(ans)){
        cout<<ans.at(i)<<endl;
    }
    rep(i,K-sz(ans)){
        cout<<r<<endl;
    }
}