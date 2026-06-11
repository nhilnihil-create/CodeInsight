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
    double N,T,A;
    cin>>N>>T>>A;
    vector<double> H(N);
    rep(i,N){cin>>H.at(i);}
    rep(i,N){
        H.at(i)=T-H.at(i)*0.006;
    }
    int ans=0;
    rep(i,N){
        if(abs(A-H.at(i))<abs(A-H.at(ans))){
            ans=i;
        }
    }
    cout<<ans+1<<endl;
}