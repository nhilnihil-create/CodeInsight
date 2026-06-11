#include<bits/stdc++.h>
#define Fst first
#define Snd second
#define RG register
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef unsigned long long ULL;
template<typename T> inline void read(T& x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template<typename T, typename... U> inline void read(T& x, U& ... y) {
  read(x), read(y...);
}
const int N=2e5+10;
int n,x,y,H,W;
int L[N],R[N],U[N],D[N];
char S[N],T[N];
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(H,W,n,x,y);
  scanf("%s%s",S+1,T+1);
  //if((x==1&&S[i]=='L')||(x==W&&S[i]=='R')||(y==1&&S[i]=='U')||(y==H&&S[i]=='D')) return puts("NO"),0;
  for(int i=1;i<=n;++i) {
    L[i]=L[i-1]+(S[i]=='L');  
    R[i]=R[i-1]+(S[i]=='R');
    U[i]=U[i-1]+(S[i]=='U');
    D[i]=D[i-1]+(S[i]=='D');
  }
  int last=n,lx=1,rx=W; T[0]='L';
  for(int i=n;;--i) if(T[i]=='L'||T[i]=='R') {
    int l=L[last]-L[i],r=R[last]-R[i];
    lx+=l; rx-=r;
    if(lx>rx) return puts("NO"),0;
    if(!i) break;
    if(T[i]=='L') rx=min(W,rx+1);
    else lx=max(1,lx-1);
    last=i;
  }
  if(y<lx||rx<y) return puts("NO"),0;
  last=n; lx=1; rx=H; T[0]='U';
  for(int i=n;;--i) if(T[i]=='U'||T[i]=='D') {
    int l=U[last]-U[i],r=D[last]-D[i];
    lx+=l; rx-=r;
    if(lx>rx) return puts("NO"),0;
    if(!i) break;
    if(T[i]=='U') rx=min(H,rx+1);
    else lx=max(1,lx-1);
    last=i;
  }
  if(x<lx||rx<x) return puts("NO"),0;
  puts("YES"); 
  return 0;
}
