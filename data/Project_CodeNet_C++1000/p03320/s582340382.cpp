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
 
int sum(ll x){return x<10?x:x%10+sum(x/10);}
 
int main(){
int k=read();
for (ll s=1,d=1;k--;s+=d) 
  for (write(s),pl;1.0*(s+d)/sum(s+d)>1.0*(s+(d<<1))/sum(s+(d<<1));) 
    d=(d<<3)+(d<<1);
}
/*
    令f(n)是对于某个n>N来说n/s(n)最小的正整数(如果碰到平局的情况,选择最小的那一个数.).
一开始令N=1,然后不断把f(N+1)赋值给N,我们就可以将所有的Snuke number按照递增的顺序罗列出来.
现在我们要做的是算出每一个N对应的f(N).
    我们可以证明f(N)总是可以通过把N的最后面(最不重要的)k个数字变成9而得到.
	令x=f(N).简单来说,我们令xi表示x的第i个数字(也就是x中10^i的系数).假设x>N并且第d个数字是 
x与N不相等的第一个(最重要的)数字.(注意N和x总是有相同数量的数字,比如说可以轻松证明999...999
永远是一个Snuke Number.)我们现在需要证明x0=x1=...=xd=9.
    如果对于某个i<d,xi<9,令y是那个可以被从xi变成9,并且xd变成xd-1而变成的数字.这样的话非常
清楚,N<=y<x并且s(y)>=s(x).这样与x/s(x)最小矛盾.所以x0=...=x[d-1]=9. 
    那么我们知道x0=...=x[d-1],xd不知道,并且x[d+1]以及之后的N的每一个位置上的数都不知道.
接下来我们定义z为当xd=0且w=xd的时候的x.那么可以得到x=z+w*10^d,s(x)=s(z)+w,且x/s(x)=(z+w*10^d)/(s(z)+w).
这是一个关于w的单调函数,最佳的w值既是最小的合法值,也是N的第d个位置上的数或者是最大的合法值(即9).
我们知道第d个位置的数,是x和N不等的地方,那么xd=9.(这种观察是不必要的-即使不观察,最终符合条件
的候选也是足够的.)
    那么我们已经把x的候选给限制了.对于每一个候选计算出x/s(x).f(N)就是使该值最小的数. 
*/