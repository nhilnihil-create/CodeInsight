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
int n;
long long ans,f[20][20];
char s[40];
string s1,s2;
int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	for (int mask=0;mask<(1<<n);mask++)
	{
		s1="";
		s2="";
		int l1=0,l2=0;
		for (int i=n-1;i>=0;i--)
		{
			if (mask&(1<<i))
			{
				s1.push_back(s[i]);
				l1++;
			}
			else
			{
				s2.push_back(s[i]);
				l2++;
			}
		}
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<=i && j<l1;j++)
			{
				if (s[n+i]==s1[j])
				{
					f[j+1][i-j]+=f[j][i-j];
				}
			}
			for (int j=0;j<=i && j<l2;j++)
			{
				if (s[n+i]==s2[j])
				{
					f[i-j][j+1]+=f[i-j][j];
				}
			}
		}
		ans+=f[l1][l2];
	}
	printf("%lld\n",ans);
    return 0;
}