#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<sstream>
using namespace std;
typedef long long ll;   
typedef unsigned long long ull;
inline long long read()//inline 加速读入
{
	long long x=0;char c=getchar();//x代表返回值，c代表读取的字符
	while (c<'0'||c>'9') c=getchar();//读取所有非数部分
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();//如果读取的字符为数，加入返回值
	return x;
}
 inline void write(ll x)
 {
     char F[200];
      int tmp=x>0?x:-x ;
    if(x<0)putchar('-') ;
    int cnt=0 ;
       while(tmp>0)
       {
            F[cnt++]=tmp%10+'0';
            tmp/=10;
       }
       while(cnt>0)putchar(F[--cnt]) ;
 }
int NOf1(int n) 
{

	int c=0;
	for(int i = 0; i < 32; ++i){
		if(n & 1)
			++c;
		n >>= 1;
	}
	return c;
}
const int N=200005;
int n,l;
ll ans,sum,a[N];
int main()
{
    scanf("%d",&n);l=1;
    for (int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        while ((sum^a[i])!=sum+a[i]) sum^=a[l++];
       ans+=i-l+1;sum^=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}