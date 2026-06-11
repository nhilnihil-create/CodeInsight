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
int A[200000];
int s[200000];
int v[200000];
int sz;
int add(int k, int z){
  if(k==0){
    return 0;
  }
  if(sz==0 || s[sz-1] < k){
    s[sz] = k;
    v[sz++] = 1;
    return 1;
  }
  v[sz-1]++;
  if(v[sz-1]==z){
    sz--;
    return add(k-1,z);
  }
  return 1;
}
int main(){
  int i;
  int res;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  int KL2GvlyY;
  int Q5VJL1cS;
  int e98WHCEY;
  KL2GvlyY = 1;
  Q5VJL1cS = N;
  while(KL2GvlyY < Q5VJL1cS){
    if((KL2GvlyY + Q5VJL1cS)%2==0){
      e98WHCEY = (KL2GvlyY + Q5VJL1cS) / 2;
    }
    else{
      e98WHCEY = (KL2GvlyY + Q5VJL1cS - 1) / 2;
    }
    sz = 0;
    for(i=(1);i<(N);i++){
      if(A[i-1] < A[i]){
        continue;
      }
      while(sz && s[sz-1] > A[i]){
        sz--;
      }
      if(e98WHCEY==1){
        break;
      }
      if(!add(A[i],e98WHCEY)){
        break;
      }
    }
    if(i==N){
      Q5VJL1cS = e98WHCEY;
    }
    else{
      KL2GvlyY = e98WHCEY + 1;
    }
  }
  res =Q5VJL1cS;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// int N, A[2d5];
// int s[2d5], v[2d5], sz;
// 
// int add(int k, int z){
//   if(k==0) return 0;
//   
//   if(sz==0 || s[sz-1] < k){
//     s[sz] = k;
//     v[sz++] = 1;
//     return 1;
//   }
//   v[sz-1]++;
//   if(v[sz-1]==z){
//     sz--;
//     return add(k-1,z);
//   }
//   return 1;
// }
// 
// {
//   int i, res;
//   rd(N,A(N));
//   res = bsearch_min[int,z,1,N][
//     sz = 0;
//     rep(i,1,N){
//       if(A[i-1] < A[i]) continue;
//       while(sz && s[sz-1] > A[i]) sz--;
//       if(z==1) break;
//       if(!add(A[i],z)) break;
//     }
//   ](i==N);
//   wt(res);
// }
