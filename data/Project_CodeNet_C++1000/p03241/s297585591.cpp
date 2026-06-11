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
    int ans=1;
    for(int i=1;i*i<=M;i++){
        if(M%i!=0)continue;
        int x=M/i;
        if(x>=N){chmax(ans,i);}
        if(i>=N){chmax(ans,x);}
    }
    cout<<ans<<endl;
}