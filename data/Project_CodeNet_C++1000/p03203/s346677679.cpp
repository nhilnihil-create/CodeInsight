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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int X;
int Y;
int N;
set<int> xs[200000];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  int res = 1000000000;
  rd(X);
  rd(Y);
  rd(N);
  for(i=(0);i<(Y);i++){
    xs[i].insert(X);
  }
  for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
    rd(i);i += (-1);
    rd(j);j += (-1);
    xs[j].insert(i);
  }
  i = j = 0;
  for(;;){
    k = *(xs[j].lower_bound(i+1));
    chmin(res, k);
    if(k == i+1){
      break;
    }
    i++;
    if(j+1 == Y){
      break;
    }
    k = *(xs[j+1].lower_bound(i));
    if(k != i){
      j++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// int X, Y, N;
// set<int> xs[2d5];
// 
// {
//   int i, j, k;
//   int res = 1d9;
//   
//   rd(X,Y,N);
//   rep(i,Y) xs[i].insert(X);
//   
//   rep(N){
//     rd(i--,j--);
//     xs[j].insert(i);
//   }
// 
//   i = j = 0;
//   for(;;){
//     k = *(xs[j].lower_bound(i+1));
//     res <?= k;
//     if(k == i+1) break;
//     i++;
// 
//     if(j+1 == Y) break;
//     k = *(xs[j+1].lower_bound(i));
//     if(k != i) j++;
//   }
// 
//   wt(res);
// }
