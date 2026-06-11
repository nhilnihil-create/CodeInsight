#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
int keta(int x){
    int ret=1;
    while(x>=10){
        x/=10;
        ret++;
    }
    return ret;
}

signed main(){
    int N;cin>>N;
    bool ok=true;
    string S=to_string(N);
    REPS(i,S.size()-1)if(S[i]!='9')ok=false;
    if(ok) cout<<9*(keta(N)-1)+(S[0]-'0')<<endl;
    else{
      if(keta(N)!=1)cout<<(int)(S[0]-'0')-1+9*(keta(N)-1)<<endl;
      else cout<<S[0]-'0'<<endl;
    }
}
