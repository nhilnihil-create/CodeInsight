#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);
    map<int64_t,int64_t> mp;
    rep(m,0,M){
        int b,c; cin>>b>>c;
        mp[-c]+=b;
    }

    sort(ToEnd(A));
    int idx=-1;
    auto itr=mp.begin();
    rep(i,0,N){
        if(i-idx>itr->second){
            idx=i-1;
            itr++;
        }
        if(itr==mp.end()) break;
        if(-(itr->first)<A.at(i)) break;

        A.at(i)=-(itr->first);
    }

    int64_t ans=0;
    for(auto a:A) ans+=a;
    cout<<ans<<endl;
}