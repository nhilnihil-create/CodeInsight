#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    string S;int K;
    cin>>S>>K;
    map<string,int>memo;
    for(int i=1;i<=K;i++){
        for(int j=0;j+i<=S.size();j++){
            string D=S.substr(j,i);
            memo[D]++;
        }
    }
    auto it=memo.begin();
    advance(it,K-1);
    cout<<it->first<<endl;
}