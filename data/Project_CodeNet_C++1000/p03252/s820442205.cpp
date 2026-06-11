#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S,T; cin>>S>>T;

    vector<int> vS(S.size(),-1),vT(T.size(),-1);
    map<char,int> mpS,mpT;
    rep(i,0,S.size()){
        char cS=S.at(i),cT=T.at(i);

        if(mpS.count(cS)){
            vS.at(i)=mpS[cS];
        }else{
            mpS[cS]=i;
        }

        if(mpT.count(cT)){
            vT.at(i)=mpT[cT];
        }else{
            mpT[cT]=i;
        }
    }

    string ans="No";
    if(vS==vT) ans="Yes";
    cout<<ans<<endl;
}