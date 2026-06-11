#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
long long ans,n,a[202020],b[202020];
long long ck(long long x)
{
	long long now=1<<(x+1),c[202020],cnt=0;
	for(int i=0;i<n;i++)
	{
		c[i]=b[i]%now;
	}
	sort(c,c+n);
	for(int i=0;i<n;i++)
	{
		long long all=a[i]%now,s=lower_bound(c,c+n,(1<<(x+1))-all)-1-lower_bound(c,c+n,(1<<x)-all)+lower_bound(c,c+n,(1<<(x+2))-all)-1-lower_bound(c,c+n,(1<<(x+1))+(1<<x)-all);
		cnt+=s;
	}
	return cnt&1;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<=28;i++)
	{
        if(ck(i))
        {
        	ans+=(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}