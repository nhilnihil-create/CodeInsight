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
    int C[N-1],S[N-1],F[N-1];
    REP(i,N-1)cin>>C[i]>>S[i]>>F[i];
    REP(i,N){
        int nowT=0;
        if(i==N-1){
            cout<<0<<endl;
            break;
        }
        for(int j=i;j<N-1;j++){
            if(S[j]>=nowT)nowT=S[j];
            else{
                int z=S[j];
                while(nowT>z)z+=F[j];
                nowT=z;
            }
            nowT+=C[j];
        }
        cout<<nowT<<endl;
    }
}