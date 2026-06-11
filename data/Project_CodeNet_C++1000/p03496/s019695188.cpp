#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
int N;
int A[50];
int main(){
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  int KL2GvlyY;
  int Q5VJL1cS = 0;
  int e98WHCEY;
  int cTE1_r3A;
  int RZTsC2BF;
  for(KL2GvlyY=(0);KL2GvlyY<((N-1)+1);KL2GvlyY++){
    cTE1_r3A = abs(A[KL2GvlyY]);
    if(Q5VJL1cS==0 || e98WHCEY<cTE1_r3A){
      e98WHCEY = cTE1_r3A;
      Q5VJL1cS = 1;
      RZTsC2BF = KL2GvlyY;
    }
  }
  int i = RZTsC2BF;
  wt_L(2*N);
  wt_L('\n');
  if(A[i] >= 0){
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(2);FmcKpFmN++){
      wt_L(i+1);
      wt_L(' ');
      wt_L(1);
      wt_L('\n');
    }
    for(i=(1);i<(N);i++){
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(2);xr20shxY++){
        wt_L(i);
        wt_L(' ');
        wt_L(i+1);
        wt_L('\n');
      }
    }
  }
  else{
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(2);WYIGIcGE++){
      wt_L(i+1);
      wt_L(' ');
      wt_L(N);
      wt_L('\n');
    }
    for(i=(N)-1;i>=(1);i--){
      int t_ynMSdg;
      for(t_ynMSdg=(0);t_ynMSdg<(2);t_ynMSdg++){
        wt_L(i+1);
        wt_L(' ');
        wt_L(i);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// int N, A[50];
// {
//   rd(N,A(N));
//   int i = argmax[k=0---N-1](abs(A[k]));
// 
//   wt(2N);
//   if(A[i] >= 0){
//     rep(2) wt(i+1, 1);
//     rep(i,1,N) rep(2) wt(i, i+1);
//   } else {
//     rep(2) wt(i+1, N);
//     rrep(i,1,N) rep(2) wt(i+1, i);
//   }
// }
