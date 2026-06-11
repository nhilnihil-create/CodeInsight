#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int k;
long long a[20010],b[20010];
long long cal(long long x)
{
	long long res=0;
	while (x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	int cnt=0;
	long long now=1,cur=0;
	for (int i=0;i<=15;i++)
	{
		for (int j=0;j<1000 && now*j+cur<=1e15;j++)
		{
			a[cnt]=now*j+cur;
			cnt++;
		}
		cur+=now*9;
		now*=10;
	}
	sort(a,a+cnt);
	cnt=unique(a,a+cnt)-a;
	for (int i=0;i<cnt;i++)
	{
		b[i]=cal(a[i]);
	}
	scanf("%d",&k);
	for (int i=1;i<cnt && k;i++)
	{
		bool f=true;
		for (int j=i+1;j<cnt;j++)
		{
			if (a[i]*b[j]>a[j]*b[i])
			{
				f=false;
				break;
			}
		}
		if (f)
		{
			k--;
			printf("%lld\n",a[i]);
		}
	}
    return 0;
}