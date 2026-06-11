#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353,INF=1e18;



int main() {
    string S;
    cin>>S;
    int count=0;
    rep(i,S.size()){
        if(S.at(i)=='x')count++;
    }
    if(count>7){cout<<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
}