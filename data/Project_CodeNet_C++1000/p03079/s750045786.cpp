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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int main(){
  int A;
  int B;
  int C;
  rd(A);
  rd(B);
  rd(C);
  if(A==B && B==C){
    wt_L("Yes");
    wt_L('\n');
  }
  else{
    wt_L("No");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// {
//   int A,B,C;
//   rd(A,B,C);
//   wt(if[A==B==C, "Yes", "No"]);
// }
