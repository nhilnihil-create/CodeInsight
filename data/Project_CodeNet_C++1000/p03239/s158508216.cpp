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
    int N,T;
    cin>>N>>T;
    vector<P> ct(N);
    rep(i,N){
        cin>>ct.at(i).first>>ct.at(i).second;
    }
    int ans=10000;
    rep(i,N){
        if(ct.at(i).second<=T){
            chmin(ans,ct.at(i).first);
        }
    }
    if(ans==10000){
        cout<<"TLE"<<endl;
        return 0;
    }
    cout<<ans<<endl;
}