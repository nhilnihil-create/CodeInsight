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
    int N;
    cin>>N;
    vector<set<int>> to(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        --a;--b;
        to[a].insert(b);
        to[b].insert(a);
    }
    vector<int> C(N);
    rep(i,N){
        cin>>C.at(i);
    }
    sort(C.begin(),C.end());
    vector<int> ans(N);
    ll point=0;
    rep(i,N-1){
        int sma;
        rep(j,N){
            if(to[j].size()==1){
                sma=j;
                break;
            }
        }
        ans.at(sma)=C.at(i);
        to[*begin(to[sma])].erase(sma);
        to[sma].erase(*begin(to[sma]));
    }
    rep(i,N){
        if(ans.at(i)==0)ans.at(i)=C.at(N-1);
    }
    rep(i,N-1){
        point+=C.at(i);
    }
    cout<<point<<endl;
    rep(i,N-1){
        cout<<ans.at(i)<<" ";
    }
    cout<<ans.at(N-1)<<endl;
}