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
    int N;
    cin>>N;
    vector<int> p(N);
    rep(i,N)cin>>p.at(i);
    sort(p.begin(),p.end());
    ll ans=0;
    rep(i,N){
        if(i==N-1)ans+=p.at(i)/2;
        else ans+=p.at(i);
    }
    cout<<ans<<endl;
}