#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    string S;
    int64_t ans=0, sA=0, Bs=0,BsA=0;
    rep(n,0,N){
        cin>>S;
        rep(i,0,S.size()-1){
            if(S.at(i)=='A' && S.at(i+1)=='B') ans++;
        }

        if(S.front()=='B' && S.back()=='A') BsA++;
        else if(S.front()=='B') Bs++;
        else if(S.back()=='A') sA++;
    }

    if(BsA) ans+=BsA-1;
    if(sA>Bs) ans+=Bs+(BsA>0);
    else ans+=sA+(BsA>0 && Bs>0);

    cout<<ans<<endl;
}