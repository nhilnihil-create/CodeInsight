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
    string S;
    cin>>N>>S;
    vector<int> white(N+1);
    rep(i,N){
        white.at(i+1)=white.at(i);
        if(S.at(i)=='.')white.at(i+1)++;
    }
    int ans=N;
    rep(i,N+1){
        int now=i+white.at(N)-white.at(i)*2;
        chmin(ans,now);
    }
    cout<<ans<<endl;
}