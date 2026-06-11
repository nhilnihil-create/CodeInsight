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

ll power(ll n,ll p){
    if(p==0){return 1;}
    if(p%2==1){return n*power(n,(p-1)/2)*power(n,(p-1)/2);}
    else{return power(n,p/2)*power(n,p/2);}
}

int main() {
    int N;
    vector<int> A(3);
    cin>>N>>A.at(0)>>A.at(1)>>A.at(2);
    vector<int> L(N);
    rep(i,N)cin>>L.at(i);
    int ans=1e9;
    rep(kouho,power(4,N)){
        int MP=-30;
        int x=kouho;
        vector<int> go(N);
        rep(i,N){
            go.at(i)=x%4;
            x/=4;
        }
        int one=0,two=0,three=0;
        rep(i,N){
            if(go.at(i)==1){
                one+=L.at(i);
                MP+=10;
            }
            if(go.at(i)==2){
                two+=L.at(i);
                MP+=10;
            }
            if(go.at(i)==3){
                three+=L.at(i);
                MP+=10;
            }
        }
        if(!(one && two && three))continue;
        vector<int> sa={one,two,three};
        sort(sa.rbegin(),sa.rend());
        rep(i,3){
            MP+=abs(sa.at(i)-A.at(i));
        }
        chmin(ans,MP);
    }
    cout<<ans<<endl;
}