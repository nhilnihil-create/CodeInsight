#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<complex>
#include<vector>
#include<cstdio>
#include<string>
#include<bitset>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Set(x,y) memset(x,y,sizeof(x))
#define FILE "a"
#define mp make_pair
#define pb push_back
#define RG register
#define il inline
using namespace std;
typedef unsigned long long ull;
typedef vector<int>VI;
typedef long long ll;
typedef double dd;
const int N=100010;
const int mod=19940417;
const int base=26;
const dd eps=1e-6;
const int inf=2147483647;
const ll INF=1ll<<60;
const ll P=100000;
il ll read(){
  RG ll data=0,w=1;RG char ch=getchar();
  while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
  if(ch=='-')w=-1,ch=getchar();
  while(ch<='9'&&ch>='0')data=data*10+ch-48,ch=getchar();
  return data*w;
}

il void file(){
  srand(time(NULL)+rand());
  freopen(FILE".in","r",stdin);
  freopen(FILE".out","w",stdout);
}

int n,m,x[N],y[N],p[N],q[N],k[N],s[N];
il void er(){puts("-1");exit(0);}
int main()
{
  n=read();m=31;
  for(RG int i=1;i<=n;i++){
    x[i]=read();y[i]=read();
    p[i]=x[i]+y[i];q[i]=x[i]-y[i];
    x[i]=abs(x[i]);y[i]=abs(y[i]);
    if(i!=1&&((x[i-1]+y[i-1])&1)!=((x[i]+y[i])&1))er();
  }
  m+=(!((x[n]+y[n])&1));
  printf("%d\n",m);
  for(RG int i=0;i<31;i++)printf("%d ",1<<i);
  if(!((x[n]+y[n])&1))printf("1 ");puts("");
  for(RG int i=1;i<=n;i++){
    memset(k,0,sizeof(k));memset(s,0,sizeof(s));
    //printf("%d,%d\n",p[i],q[i]);
    if(m==32){k[32]=s[32]=1;p[i]--;q[i]--;}
    for(RG int j=30;~j;j--)
      if(p[i]>0)k[j+1]=1,p[i]-=(1<<j);
      else k[j+1]=0,p[i]+=(1<<j);
    for(RG int j=30;~j;j--)
      if(q[i]>0)s[j+1]=1,q[i]-=(1<<j);
      else s[j+1]=0,q[i]+=(1<<j);
    for(RG int j=1;j<=m;j++)
      if(k[j]&&s[j])putchar('R');
      else if(k[j]&&!s[j])putchar('U');
      else if(!k[j]&&s[j])putchar('D');
      else if(!k[j]&&!s[j])putchar('L');
    puts("");
  }
  return 0;
}
