#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rec register char
#define rel register ll
#define gc getchar
#define pc putchar
#define p32 pc(' ')
#define pl puts("")
/*By Citrus*/
inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return 0&pc(48);
  if (x<0) x=-x,pc('-');
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int yuzu=2e5;
typedef ll fuko[yuzu|10];
fuko a,b;int n;

void merge_sort(ll *a,ll mod){
int pos=n+1,i;
for (i=1;i<=n;++i){
  if (pos>n&&a[i]>=mod) pos=i;
  a[i]&=mod-1;
  }inplace_merge(a+1,a+pos,a+n+1);
}

int get(ll x){
ll ans=0;int i,kp=n;
for (i=1;i<=n;++i){
  for (;kp>0&&a[i]+b[kp]>=x;--kp);
  ans+=n-kp; 
  }return ans&1;
}

int main(){
int i,j;
for (int t=1,zxy=0;t--;){
  n=read();
  for (i=1;i<=n;++i) read(a[i]);
  for (i=1;i<=n;++i) read(b[i]);
  sort(a+1,a+n+1),sort(b+1,b+n+1);
  ll ans=0;
  for (i=61;~i;--i){
    merge_sort(a,2ll<<i),merge_sort(b,2ll<<i);
    ans|=(get(1ll<<i)^get(2ll<<i)^get(3ll<<i))<<i;
    }
  //printf("Case #%d: ",++zxy);
  write(ans),pl;
  }
}