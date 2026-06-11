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
    int N,M;
    cin>>N>>M;
    vector<int> A(N);
    rep(i,N){cin>>A.at(i);}
    sort(A.begin(),A.end());
    vector<P> sousa(M);
    rep(i,M){
        int B,C;
        cin>>B>>C;
        sousa.at(i).first=C;
        sousa.at(i).second=B;
    }
    sort(sousa.rbegin(),sousa.rend());
    int pa=0,ps=0,count=0;
    while(pa<N && ps<M){
        if(A.at(pa)>=sousa.at(ps).first){pa++;continue;}
        A.at(pa)=sousa.at(ps).first;
        pa++;
        count++;
        if(count>=sousa.at(ps).second){
            ps++;
            count=0;
        }
    }
    ll ans=0;
    rep(i,N){
        ans+=A.at(i);
    }
    cout<<ans<<endl;
}