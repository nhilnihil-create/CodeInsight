#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<pair<int,int>> X(N);
    rep(n,0,N){
        int x; cin>>x;
        X.at(n)=make_pair(x,n);
    }
    sort(ToEnd(X));

    vector<int> Ans(N);
    rep(n,0,N){
        if(n<N/2) Ans.at(X.at(n).second)=X.at(N/2).first;
        else Ans.at(X.at(n).second)=X.at(N/2-1).first;
    }

    for(auto ans:Ans) cout<<ans<<endl;
}