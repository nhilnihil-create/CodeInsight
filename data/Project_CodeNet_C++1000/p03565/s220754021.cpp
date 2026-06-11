#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S,T; cin>>S>>T;

    string ans="UNRESTORABLE";
    _rep(i,S.size()-1,T.size()-1){
        string _S=S;
        bool unmatch=false;
        rep(j,0,T.size()){
            if(S.at(i-j)=='?' || S.at(i-j)==T.at(T.size()-1-j)){
                _S.at(i-j)=T.at(T.size()-1-j);
            }else{
                unmatch=true;
                break;
            }
        }
        if(unmatch) continue;

        ans=_S;
        break;
    }

    rep(i,0,ans.size()){
        if(ans.at(i)=='?') ans.at(i)='a';
    }
    cout<<ans<<endl;
}