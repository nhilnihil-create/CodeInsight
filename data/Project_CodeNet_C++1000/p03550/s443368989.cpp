#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline void rd(int &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
int Z;
int W;
int A[2000];
int main(){
  int res;
  rd(N);
  rd(Z);
  rd(W);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  if(N==1){
    res = abs(A[0] - W);
  }
  else{
    res =max_L(abs(A[N-2] - A[N-1]), abs(A[N-1] - W));
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// int N, Z, W, A[2000];
// {
//   int res;
//   rd(N,Z,W,A(N));
//   if(N==1) res = abs(A[0] - W);
//   else     res = max(abs(A[N-2] - A[N-1]), abs(A[N-1] - W));
//   wt(res);
// }
