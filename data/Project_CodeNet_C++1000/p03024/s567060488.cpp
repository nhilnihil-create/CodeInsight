#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int K;
char S[17];
int main(){
  int i, res=0;
  K = rd(S);
  for(i=0;i<K;i++){
    if(S[i]=='x'){
      res++;
    }
  }
  if(res<=7){
    wt_L("YES");
    wt_L('\n');
  }
  else{
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190609-1

// --- original code ---
// int K; char S[17];
// {
//   int i, res = 0;
//   rd(S@K);
//   rep(i,K) if(S[i]=='x') res++;
//   wt( if[res<=7, "YES", "NO"] );
// }
