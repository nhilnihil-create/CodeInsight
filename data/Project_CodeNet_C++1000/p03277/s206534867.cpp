#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#define ll long long
#define INF 1000000000
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rev(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define pq priority_queue
#define PI acos(-1)

namespace IO
{
#define p(x) ('0'<=x&&x<='9')
	char cc; int C;
	template <class T>
	void read( T &x )
	{
		x=0; cc=getchar(); C=1;
		while(!p(cc)) { if(cc=='-') C=-1; cc=getchar(); }
		while(p(cc)) { x=x*10+cc-48; cc=getchar(); }
		x*=C;
	}
#undef p
}

using namespace IO;
using namespace std;

#define N 100005

#define lb(x) (x&-x)
int a[N],b[N],c[N],n;
ll Arr[N<<1],Arr_minor[N<<1],tot,tot_minor,tot_zero;

ll sigema(int pos)
{
	ll ret=0;
	while(pos)
	{
		ret+=Arr[pos];
		pos-=lb(pos);
	}
	return ret;
}

void add(int pos)
{
	++tot;
	while(pos<=N) ++Arr[pos],pos+=lb(pos);
}

ll sigema_minor(int pos)
{
	ll ret=0;
	while(pos)
	{
		ret+=Arr_minor[pos];
		pos-=lb(pos);
	}
	return ret;
}

void add_minor(int pos)
{
	++tot_minor;
	while(pos<=N) ++Arr_minor[pos],pos+=lb(pos);
}

#undef lb

void init()
{
	read(n);
	For(i,1,n) read(a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
#ifdef LOCAL
	freopen("./tmp/input.txt", "r", stdin);
#endif
	init();
	int L=1,R=n,mid,pre,ans;
	ll sum;
	const ll total=1LL*n*(n+1)/2;
	const ll target=(total/2)+1;
	while(L<R)
	{
		mid=(L+R)>>1;

		memset(Arr,0,sizeof(Arr)); tot=0;
		memset(Arr_minor,0,sizeof(Arr)); tot_minor=0;
		tot_zero=0;

		For(i,1,n) c[i]=(a[i]<=b[mid]?1:-1);
		sum=pre=0;
		++tot_zero;
		For(i,1,n)
		{
			pre+=c[i];
			if(pre<0)
			{
				sum+=tot_minor;
				sum-=sigema_minor(-pre);
				add_minor(-pre);
				continue;
			}
			if(pre==0)
			{
				sum+=tot_minor;
				++tot_zero;
				continue;
			}
			if(pre>0)
			{
				sum+=tot_minor+tot_zero;
				sum+=sigema(pre-1);
				add(pre);
				continue;
			}
		}
		if(sum>=target) R=mid;
		else L=mid+1;
	}

	printf("%d\n",b[L]);

	return 0;
}
