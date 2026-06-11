#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
inline void wt_L(double x){
  printf("%.15f",x);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    putchar_unlocked(x[i]);
  }
}
int N;
int A;
int dp[200001];
int main(){
  int Lj4PdHRW;
  rd(N);
  for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
    rd(A);
    dp[A] = dp[A-1] + 1;
  }
  {
    int e98WHCEY;
    int cTE1_r3A;
    if(N+1==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = dp[0];
      for(e98WHCEY=(1);e98WHCEY<(N+1);e98WHCEY++){
        cTE1_r3A = max_L(cTE1_r3A, dp[e98WHCEY]);
      }
    }
    wt_L(N -cTE1_r3A);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int N, A, dp[200001];
// {
//   rd(N);
//   rep(N){
//     rd(A);
//     dp[A] = dp[A-1] + 1;
//   }
//   wt(N - max(dp(N+1)));
// }
