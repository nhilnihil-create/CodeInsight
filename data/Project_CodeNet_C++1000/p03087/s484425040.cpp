#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,Q; cin>>N>>Q;
    string S; cin>>S;
    vector<pair<int,int>> SubS(Q);
    rep(q,0,Q){
        int l,r; cin>>l>>r;
        SubS.at(q)=make_pair(l-1,r-1);
    }

    vector<int> CumSum(S.size(),0);
    rep(i,1,S.size()){
        char pre_c=S.at(i-1), c=S.at(i);
        if(pre_c=='A' && c=='C') CumSum.at(i)=CumSum.at(i-1)+1;
        else CumSum.at(i)=CumSum.at(i-1);
    }

    for(auto s:SubS){
        int ans=CumSum.at(s.second);
        if(s.first>0) ans-=CumSum.at(s.first);

        cout<<ans<<endl;
    }
}