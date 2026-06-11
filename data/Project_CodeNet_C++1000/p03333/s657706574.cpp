#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn=100000;

int read()
{
  int x=0,f=1;
  char ch=getchar();
  while((ch<'0')||(ch>'9'))
    {
      if(ch=='-')
        {
          f=-f;
        }
      ch=getchar();
    }
  while((ch>='0')&&(ch<='9'))
    {
      x=x*10+ch-'0';
      ch=getchar();
    }
  return x*f;
}

struct seg
{
  int l,r,flag;
};

seg s[maxn+10];

bool cmpl(int a,int b)
{
  return s[a].l>s[b].l;
}

bool cmpr(int a,int b)
{
  return s[a].r<s[b].r;
}

int n,a[maxn+10],b[maxn+10];
long long rans;

inline int dist(int now,int to)
{
  if(now<s[to].l)
    {
      return s[to].l-now;
    }
  else if(now>s[to].r)
    {
      return now-s[to].r;
    }
  else
    {
      return 0;
    }
}

inline int getnow(int now,int to)
{
  if(now<s[to].l)
    {
      return s[to].l;
    }
  else if(now>s[to].r)
    {
      return s[to].r;
    }
  else
    {
      return now;
    }
}

int main()
{
  n=read();
  for(int i=1; i<=n; ++i)
    {
      s[i].l=read();
      s[i].r=read();
      a[i]=b[i]=i;
    }
  std::sort(a+1,a+n+1,cmpl);
  std::sort(b+1,b+n+1,cmpr);
  int left=1,right=1,now=0;
  long long ans=0;
  s[a[1]].flag=1;
  ans+=dist(now,a[1]);
  now=getnow(now,a[1]);
  for(int i=1; i<n; ++i)
    {
      while(s[a[left]].flag)
        {
          ++left;
        }
      while(s[b[right]].flag)
        {
          ++right;
        }
      if(dist(now,a[left])>dist(now,b[right]))
        {
          s[a[left]].flag=1;
          ans+=dist(now,a[left]);
          now=getnow(now,a[left]);
        }
      else
        {
          s[b[right]].flag=1;
          ans+=dist(now,b[right]);
          now=getnow(now,b[right]);
        }
    }
  for(int i=1; i<=n; ++i)
    {
      s[i].flag=0;
    }
  rans=ans+abs(now);
  left=right=1;
  now=ans=0;
  s[b[1]].flag=1;
  ans+=dist(now,b[1]);
  now=getnow(now,b[1]);
  for(int i=1; i<n; ++i)
    {
      while(s[a[left]].flag)
        {
          ++left;
        }
      while(s[b[right]].flag)
        {
          ++right;
        }
      if(dist(now,a[left])>dist(now,b[right]))
        {
          s[a[left]].flag=1;
          ans+=dist(now,a[left]);
          now=getnow(now,a[left]);
        }
      else
        {
          s[b[right]].flag=1;
          ans+=dist(now,b[right]);
          now=getnow(now,b[right]);
        }
    }
  printf("%lld\n",std::max(ans+abs(now),rans));
  return 0;
}