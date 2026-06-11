#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,Q,i,j;scanf("%d%d%d",&N,&M,&Q);
  int t[N][N],L,R;
  for(i=0;i<N;i++){
    fill(t[i],t[i]+N,0);
  }
  for(i=0;i<M;i++){
    scanf("%d%d",&L,&R);L--;R--;
    t[L][R]++;
  }
  for(i=N-2;i>=0;i--){
    for(j=0;j<N;j++) t[i][j] += t[i+1][j];
  }
  for(i=0;i<N;i++){
    for(j=1;j<N;j++) t[i][j] += t[i][j-1];
  }
  int p,q;
  for(i=0;i<Q;i++){
    scanf("%d%d",&p,&q);p--;q--;
    printf("%d\n",t[p][q]);
  }
}