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
    int A[N];
    REP(i,N)cin>>A[i];
    int ans=0;
    bool ok=true;
    REP(i,N){
        if(i==0){
          	if(A[i]!=0){
            	ok=false;
            	break;
            }
        }
        else{
            if(A[i]-A[i-1]>1){
                ok=false;
                break;
            }
            if(A[i]-A[i-1]==1)ans++;
            if(A[i]-A[i-1]<=0)ans+=A[i];
        }
    }
    cout<<(ok?ans:-1)<<endl;
}