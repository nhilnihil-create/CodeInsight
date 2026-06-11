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
    string S;
    cin>>S;
    int c0=0,c1=0;
    rep(i,sz(S)){
        if(S.at(i)=='0')c0++;
        else c1++;
    }
    cout<<min(c0,c1)*2<<endl;
}