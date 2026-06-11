#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    string Q="keyence";
    int fidx,lidx;

    int idx=0;
    rep(i,0,S.size()){
        fidx=i;
        if(i>=Q.size() || S.at(i)!=Q.at(i)) break;
    }

    idx=Q.size()-1;
    _rep(i,S.size()-1,0){
        lidx=i;
        int qidx=i-(S.size()-Q.size());
        if(qidx<0 || S.at(i)!=Q.at(qidx)) break;
    }

    string ans="YES";
    if(lidx>=fidx && Q!=S.erase(fidx,lidx-fidx+1)) ans="NO";
    cout<<ans<<endl;
}