#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

int main(){
  int N,M,Q; 
  scanf("%d%d%d",&N,&M,&Q);
  
  int a[N+1]={},b[N+1][N+1]={},L,R;
  REP(_,M){
    scanf("%d%d",&L,&R);
    a[R]++;
    REP(i,R-L){
      b[L+i+1][R]++;
    }
  }
  REP(i,N) a[i+1]=a[i]+a[i+1];
  REP(i,N) REP(j,N) b[i+1][j+1]=b[i+1][j]+b[i+1][j+1];
  
  int p,q;
  REP(_,Q){
    scanf("%d%d",&p,&q);
    printf("%d\n",a[q]-a[p-1]-b[p][q]);
  }
}