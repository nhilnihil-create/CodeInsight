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

    map<int64_t,int64_t> mp;
    mp[0]++;
    int64_t sumA=0;
    rep(n,0,N){
        sumA+=A.at(n);
        mp[sumA]++;
    }

    int64_t ans=0;
    for(auto m:mp){
        ans+=m.second*(m.second-1)/2;
    }

    cout<<ans<<endl;
}