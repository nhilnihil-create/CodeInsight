#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N),B(N);
    rep(n,0,N) cin>>A.at(n);
    rep(n,0,N) cin>>B.at(n);

    int64_t aRem=0;
    rep(i,0,N){
        if(A.at(i)>B.at(i)) aRem+=(A.at(i)-B.at(i))*2;
    }

    rep(i,0,N){
        if(A.at(i)<B.at(i)) aRem-=min(aRem,2*((B.at(i)-A.at(i))/2));
    }
    
    string ans="Yes";
    if(aRem) ans="No";
    cout<<ans<<endl;
}