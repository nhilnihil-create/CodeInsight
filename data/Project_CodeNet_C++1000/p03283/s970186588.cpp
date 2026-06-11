#include <bits/stdc++.h> 
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;


int rec[550][550];

int main(){
    int N,M,Q; cin>>N>>M>>Q;
    int L[M],R[M];
    int p[Q],q[Q];
    rep(i,M) cin>>L[i]>>R[i];
    rep(i,Q) cin>>p[i]>>q[i];
    rep(i,M){
        rec[L[i]][R[i]]++;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N-1;j++){
            rec[i][j+1]+=rec[i][j];
        }
    }
     for(int j=1;j<=N;j++){
        for(int i=N+1;i>0;i--){
            rec[i-1][j]+=rec[i][j];
        }
    }

    rep(i,Q){
        cout<<rec[p[i]][q[i]]<<endl;
    }

    
}