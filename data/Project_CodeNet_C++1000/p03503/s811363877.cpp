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
const int MAX=3000;

signed main(){
    int N;cin>>N;
    int F[N][10];
    int P[N][11];
    REP(i,N)REP(j,10)cin>>F[i][j];
    REP(i,N)REP(j,11)cin>>P[i][j];
    int ans=-INF;
    for(int tmp=1;tmp<(1<<10);tmp++){
        bitset<10> s(tmp);
        int preans=0;
        REP(i,N){
            int count=0;
            REP(j,10){
                if(s.test(j)&&F[i][j]==1)count++;
            }
            preans+=P[i][count]; 	
        }
        ans=max(preans,ans);
    }
    cout<<ans<<endl;
}
