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
    int N,D,X;cin>>N>>D>>X;
    REP(i,N){
        int a;cin>>a;
        X+=1+(D-1)/a;
    }
    cout<<X<<endl;
}