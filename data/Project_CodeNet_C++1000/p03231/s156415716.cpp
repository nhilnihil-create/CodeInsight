#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t Gcd(int64_t a,int64_t b){
    if(a%b==0) return b;
    Gcd(b,a%b);
}

int main(){
    int64_t N,M; cin>>N>>M;
    string S,T; cin>>S>>T;

    int64_t g=Gcd(N,M);
    bool possible=true;
    rep(i,0,g){
        if(S.at(N/g*i)!=T.at(M/g*i)) possible=false;
    }

    int64_t ans=-1;
    if(possible) ans=N/g*M;

    cout<<ans<<endl;
}