#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

uint64_t ans=0;

void dfs(vector<int> S,int idx){
    if(idx>S.size()-1){
        int num=1;
        for(auto s:S) num*=s;
        if(num%2==0) ans++;
        return;
    }

    dfs(S,idx+1);
    vector<int> _S=S;
    _S.at(idx)=S.at(idx)-1;
    dfs(_S,idx+1);
    _S.at(idx)=S.at(idx)+1;
    dfs(_S,idx+1);
}

int main(){
    int N; cin>>N;
    vector<int> S(N);
    rep(n,0,N) cin>>S.at(n);

    dfs(S,0);
    cout<<ans<<endl;
}