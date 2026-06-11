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
int as;
int a[30000];
int bs;
int b[30000];
int cs;
int c[30000];
int res[20000];
int ress;
int main(){
  int i;
  rd(N);
  for(i=(30001)-1;i>=(1);i--){
    if(i%6==0){
      c[cs++] = i;
      continue;
    }
    if(i%2==0){
      a[as++] = i;
      continue;
    }
    if(i%3==0){
      b[bs++] = i;
      continue;
    }
  }
  if(N==3){
    res[ress++] = 2;
    res[ress++] = 5;
    res[ress++] = 63;
  }
  else{
    int Q5VJL1cS, RZTsC2BF;
    for(Q5VJL1cS=(0);Q5VJL1cS<(2);Q5VJL1cS++){
      res[ress++] = a[--as];
      N--;
    }
    for(RZTsC2BF=(0);RZTsC2BF<(2);RZTsC2BF++){
      res[ress++] = b[--bs];
      N--;
    }
    while(as >= 2 && N >= 2){
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(2);KrdatlYV++){
        res[ress++] = a[--as];
        N--;
      }
    }
    while(bs >= 2 && N >= 2){
      int V9aVTaxx;
      for(V9aVTaxx=(0);V9aVTaxx<(2);V9aVTaxx++){
        res[ress++] = b[--bs];
        N--;
      }
    }
    while(cs >= 1 && N >= 1){
      res[ress++] = c[--cs];
      N--;
    }
  }
  {
    int ZIeRIny5;
    if(ress==0){
      putchar_unlocked('\n');
    }
    else{
      for(ZIeRIny5=(0);ZIeRIny5<(ress-1);ZIeRIny5++){
        wt_L(res[ZIeRIny5]);
        wt_L(' ');
      }
      wt_L(res[ZIeRIny5]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N;
// int as, a[30000];
// int bs, b[30000];
// int cs, c[30000];
// int res[20000], ress;
// {
//   rd(N);
//   rrep(i,1,30001){
//     if(i%6==0) c[cs++] = i, continue;
//     if(i%2==0) a[as++] = i, continue;
//     if(i%3==0) b[bs++] = i, continue;
//   }
//   if(N==3){
//     res[ress++] = 2;
//     res[ress++] = 5;
//     res[ress++] = 63;
//   } else {
//     rep(2) res[ress++] = a[--as], N--;
//     rep(2) res[ress++] = b[--bs], N--;
//     while(as >= 2 && N >= 2) rep(2) res[ress++] = a[--as], N--;
//     while(bs >= 2 && N >= 2) rep(2) res[ress++] = b[--bs], N--;
//     while(cs >= 1 && N >= 1) res[ress++] = c[--cs], N--;
//   }
//   wt(res(ress));
// }
// 
