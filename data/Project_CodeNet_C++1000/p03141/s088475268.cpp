#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<tuple<int64_t,int64_t,int64_t>> D;
    rep(i,0,N){
        int64_t a,b; cin>>a>>b;
        D.emplace_back(a+b,a,b);
    }

    sort(ToEnd(D),greater<tuple<int64_t,int64_t,int64_t>>());

    int64_t ans=0,idx=0;
    for(auto d:D){
        int64_t s,a,b;
        tie(s,a,b)=d;

        if(idx%2) ans-=b;
        else ans+=a;
        idx++;
    }

    cout<<ans<<endl;
}