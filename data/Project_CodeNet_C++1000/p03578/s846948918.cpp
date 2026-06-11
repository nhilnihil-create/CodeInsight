#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    map<int,int> D;
    rep(n,0,N){
        int d; cin>>d;
        D[d]++;
    }
    int M; cin>>M;
    vector<int> T(M);
    rep(m,0,M) cin>>T.at(m);

    string ans="YES";
    for(auto t:T){
        if(D[t]>0) D[t]--;
        else{ ans="NO"; break;}
    }

    cout<<ans<<endl;
}