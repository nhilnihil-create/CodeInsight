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
    int K;cin>>K;
    vector<int>A(K);
    REP(i,K)cin>>A[i];
    reverse(A.begin(),A.end());
    int MAX_N[K],MIN_N[K];//後半i回終了前の最大最小人数
  	REP(i,K)MAX_N[i]=MIN_N[i]=0;
    bool ok=true;
    REP(i,K){
        if(i==0){
            if(A[i]>2){
                ok=false;
                break;
            }
            MAX_N[0]=3;
            MIN_N[0]=2;
        }
        else{
            if(A[i]>MAX_N[i-1]){
                ok=false;
                break;
            }
            MAX_N[i-1]-=MAX_N[i-1]%A[i];
          	if(MIN_N[i-1]>MAX_N[i-1]){
              	ok=false;
              	break;
            }
            if(MIN_N[i-1]%A[i]!=0) MIN_N[i-1]+=A[i]-(MIN_N[i-1]%A[i]);
          	if(MIN_N[i-1]>MAX_N[i-1]){
              	ok=false;
              	break;
            }
            MAX_N[i]=MAX_N[i-1]+A[i]-1;
            MIN_N[i]=MIN_N[i-1];
        }
    }
    if(ok)cout<<MIN_N[K-1]<<" "<<MAX_N[K-1]<<endl;
    else cout<<-1<<endl;
}
