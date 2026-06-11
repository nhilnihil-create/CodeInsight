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
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    sort(C.rbegin(),C.rend());
    set<tuple<ll,int,int,int>> cake;
    cake.insert({A.at(0)+B.at(0)+C.at(0),X,Y,Z});
    rep(i,K){
        tuple<ll,int,int,int> now=*rbegin(cake);
        cake.erase(now);
        ll ans;
        int a,b,c;
        tie(ans,a,b,c)=now;
        cout<<ans<<endl;
        a=X-a;b=Y-b;c=Z-c;
        if(a+1<X){cake.insert({A.at(a+1)+B.at(b)+C.at(c),X-a-1,Y-b,Z-c});}
        if(b+1<Y){cake.insert({A.at(a)+B.at(b+1)+C.at(c),X-a,Y-b-1,Z-c});}
        if(c+1<Z){cake.insert({A.at(a)+B.at(b)+C.at(c+1),X-a,Y-b,Z-c-1});}
    }
}