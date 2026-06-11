#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i, sz=0;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar_unlocked();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
char S[100002];
int main(){
  int a, b, res;
  N = rd(S);
  a = b = N/2;
  while(a-1 >= 0 && S[a]==S[a-1]){
    a--;
  }
  while(b+1 <  N && S[b]==S[b+1]){
    b++;
  }
  res = N -max_L(a, N-1-b);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190827-1

// --- original code ---
// int N; char S[100002];
// {
//   int a, b, res;
//   rd(S@N);
//   a = b = N/2;
//   while(a-1 >= 0 && S[a]==S[a-1]) a--;
//   while(b+1 <  N && S[b]==S[b+1]) b++;
//   res = N - max(a, N-1-b);
//   wt(res);
// }
