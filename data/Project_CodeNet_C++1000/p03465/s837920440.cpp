#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<cstdlib>
#define pb push_back
#define mk make_pair
#define ll long long
#define lson ch[x][0]
#define rson ch[x][1]
#include<bitset>
//贼巧妙的一个题，考虑每一个除了全集之外的每个子集，都对应了一个补集。
//我们令sum表示所有ai的和，如果一个子集的和小于sum/2,那么补集的和一定大于sum/2，这样就不会影响中位数的位置 
//那么我们会发现，由于多了一个全集，所以中位数会右偏（相对于中间），那我们就找到第一个大于(sum+1)/2的 出现过的值就可以了
//所以 我们用bitset优化这个过程
 
using namespace std;

inline int read()
{
   int x=0,f=1;char ch=getchar();
   while (!isdigit(ch)) {if (ch=='-') f=-1;ch=getchar();}
   while (isdigit(ch)) {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
   return x*f;
}

const int maxn = 2010;

bitset<maxn*maxn> b;
int n,m;
int a[maxn];
int sum;

int main()
{
   n=read();
   for (int i=1;i<=n;i++) a[i]=read();
   for (int i=1;i<=n;i++) sum+=a[i];
   b[0]=1;
   b[a[1]]=1;
   for (int i=2;i<=n;i++)
   {
      b = b | (b << a[i]);
   }
   for (int i=(sum+1)/2;i;i++) 
     if (b[i]) 
     {
        cout<<i<<endl;
        break;
     }
   return 0;
}
