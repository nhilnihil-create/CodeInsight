#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    int64_t cntA=0,ans=0;
    rep(i,0,S.size()-1){
        if(S.at(i)=='A'){
            cntA++;
        }else{
            if(S.at(i)=='B' && S.at(i+1)=='C'){
                ans+=cntA;
                i++;
            }else{
                cntA=0;
            }
        }
    }

    cout<<ans<<endl;
}