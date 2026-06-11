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
    int N,M;
    cin>>N>>M;
    vector<int> X(M);
    rep(i,M)cin>>X.at(i);
    sort(X.begin(),X.end());
    if(N>=M){
        cout<<0<<endl;
        return 0;
    }
    vector<int> sa(M-1);
    rep(i,M-1){
        sa.at(i)=X.at(i+1)-X.at(i);
    }
    sort(sa.begin(),sa.end());
    ll ans=0;
    rep(i,M-N){
        ans+=sa.at(i);
    }
    cout<<ans<<endl;
}