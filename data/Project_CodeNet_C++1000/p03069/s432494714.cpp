#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    string S; cin>>S;

    vector<int> nW(S.size()+1,0),nB(S.size()+1,0);
    rep(i,1,S.size()+1){
        nW.at(i)=nW.at(i-1);
        nB.at(i)=nB.at(i-1);

        if(S.at(i-1)=='.') nW.at(i)++;
        else nB.at(i)++;
    }

    int ans=INT_MAX;
    rep(i,0,S.size()+1){
        int _ans=nB.at(i)+(nW.back()-nW.at(i));
        ans=min(ans,_ans);
    }

    cout<<ans<<endl;
}