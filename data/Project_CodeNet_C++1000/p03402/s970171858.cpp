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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int A;
int B;
int N = 100;
char res[100][101];
int main(){
  int KL2GvlyY, Lj4PdHRW;
  int i;
  int j;
  rd(A);A += (-1);
  rd(B);B += (-1);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N/2);j++){
      res[i][j] = '.';
    }
    for(j=(N/2);j<(N);j++){
      res[i][j] = '#';
    }
  }
  i = 0;
  j = N-1;
  for(Lj4PdHRW=(0);Lj4PdHRW<(A);Lj4PdHRW++){
    res[i][j] = '.';
    i += 2;
    if(i >= N){
      i = 0;
      j -= 2;
    }
  }
  i = j = 0;
  for(KL2GvlyY=(0);KL2GvlyY<(B);KL2GvlyY++){
    res[i][j] = '#';
    i += 2;
    if(i >= N){
      i = 0;
      j += 2;
    }
  }
  wt_L(N);
  wt_L(' ');
  wt_L(N);
  wt_L('\n');
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
      wt_L(res[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// int A, B;
// int N = 100;
// char res[100][101];
// {
//   int i, j;
//   rd(A--,B--);
//   rep(i,N){
//     rep(j,N/2) res[i][j] = '.';
//     rep(j,N/2,N) res[i][j] = '#';
//   }
//   i = 0; j = N-1;
//   rep(A){
//     res[i][j] = '.';
//     i += 2;
//     if(i >= N) i = 0, j -= 2;
//   }
//   i = j = 0;
//   rep(B){
//     res[i][j] = '#';
//     i += 2;
//     if(i >= N) i = 0, j += 2;
//   }
//   wt(N, N);
//   wtLn(res(N));
// }
