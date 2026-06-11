#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<tuple<int,int,int>> Train(N-1);
    rep(n,0,N-1){
        int c,s,f; cin>>c>>s>>f;
        Train.at(n)=make_tuple(c,s,f);
    }

    vector<int> t(N,0);
    int idx=0;
    for(auto train:Train){
        int c,s,f;
        tie(c,s,f)=train;

        idx++;
        rep(i,0,idx){
            int st=ceil((double)t.at(i)/f)*f;
            st=max(st,s);
            t.at(i)=st+c;
        }
    }

    for(auto ans:t) cout<<ans<<endl;
}