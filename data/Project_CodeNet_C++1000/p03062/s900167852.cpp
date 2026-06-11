#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);

    int cnt=0;
    for(auto a:A){
        if(a<0) cnt++;
    }

    int64_t ans=0,minA=INT64_MAX;
    for(auto a:A){
        ans+=abs(a);
        minA=min(minA,abs(a));
    }

    if(cnt%2) ans-=2*minA;
    cout<<ans<<endl;
}