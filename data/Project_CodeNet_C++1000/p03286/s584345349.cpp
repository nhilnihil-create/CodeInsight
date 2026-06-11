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

signed main(){
    int N;cin>>N;
    string ans="";
    while(N!=0){
        int d=N%2;
        if(d<0)d+=2;
        N=-(N-d)/2;
        ans+=(char)(d+'0');
    }
    reverse(ans.begin(),ans.end());
    if(ans=="")ans="0";
    cout<<ans<<endl;
}