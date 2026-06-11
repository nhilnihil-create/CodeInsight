#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

int N,ans;
char S[300][600];

int main(){
    cin>>N;
    rep(i,N)rep(j,N)cin>>S[i][j];
    rep(k,N){
        bool ok=1;
        rep(i,N)rep(j,N)if(S[i][(j+k)%N]!=S[j][(i+k)%N])ok=0;
        if(ok)ans+=N;
    }
    cout<<ans<<endl;
}