#include <cstdio>
int N, C;
int s[100000],t[100000],c[100000]; 
//時刻tを何個の区間が覆っているかをsm[t]に格納する。
int sm[200002];
//以下のfor文でsmの構築のために用いる一時配列。
//各チャンネルiについて、時刻jが区間に覆われているとき、tt[j]>0となるようにする。
int tt[200002]; 

int main () {
  scanf("%d%d",&N,&C); 
  for(int i=0;i<N;i++) scanf("%d%d%d",&s[i],&t[i],&c[i]);
  for(int i=1;i<=C;i++){//各チャンネルiについて
    for(int j=0;j<200002;j++)tt[j] = 0;
    for(int j=0;j<N;j++) if(c[j]==i) tt[s[j]*2-1]++,tt[t[j]*2]--; 
    for(int j=1;j<200002;j++)tt[j]+=tt[j-1];
    for(int j=0;j<200002;j++)if(tt[j]>0)sm[j]++;
  }
  int mx = 0;//求める最大値(答え)
  for(int j=0;j<200002;j++) if(mx < sm[j]) mx = sm[j];
  printf("%d\n",mx);
}
