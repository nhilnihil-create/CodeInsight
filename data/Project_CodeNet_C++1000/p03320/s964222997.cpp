//Code by 27.
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>  
//#include<memory.h> 
#include<sstream>
#include<time.h>
#include <iomanip>
using namespace std;
const unsigned long long BIGEST=1000000000000000000+1000000000000000000;
const long long BIGER=1000000000000000000;
const int BIG=1000000000;
const int MOD=19260817;
/*
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^ =ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\`  ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo,   =/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo`    \ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooo[o\oo\oo`  ,  ,o\o/\\ooo`ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo//\           \.          =\ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo\`   ,\`,ooo/]`*    ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo/oo`   .\ooo\[   ,/\ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\^  =\\o/  ,ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo  =/`  =^  =oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^            oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/    .oo/`    =ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo^o=`  ,\oooo/o^   ]^ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo.]o/\oooooooo,.//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^ [oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo  ,/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/`  ,\/oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\//oooooooooooooo,   =^/oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo/`,`o\/ooooooooooooo`   \/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo/\\        ,,\/\oooooooo\^   ,\oooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo/^             `oooooooooo^    \ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooo\\/             /\\ooooooooooo^    ,o\=ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooo`            /oooooooooooooooo^    ,,^ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooo/ooo/            =o\ooooooooooooooooo`     ^ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo/               ,\oooooooooooooooo^\     ,ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo`                ,\[]/oooooooooooooo      ,/ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo/\        ]`       ,`\oooooooooooooo^      oooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooo\`     \o\o        \ooooooooooooooo      =\oooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooo/o=` /o/oooo^        \/\ooooooooooo      ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/o         ooooooooo\o/  n     oooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/\        .o\ooooooo/       ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo`        \/ooo\o/        ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\/         \ooo^^       ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^        ./\/        oooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\/`        .        ,oo^ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooo.  ,ooooooooooooooo                ooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooo^        `/oooooooooooo/^             oooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooo/\oo``           \/[ooo[ooooo^            ooooooooooooooooooooooooooooooooooooooooooooooooooooooo 
ooooooooooooooooooooooooooooooooooooooooooooo\,        =.        .[[[                 ,\ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo/o/o.       oooo\o`                             \o/\ooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo/o.        ]oooooooo\                            ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooo`        =ooooooooooooo`            ,oo/\         \ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooo        =oooooooooooooooooo/oooooooooooo\/.       `ooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo^^      ,ooooooooooooooooooooooooooooooooooo\    ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooo\  `,/ooooooooooooooooooooooooooooooooooooo/^ o]o/ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
*/
long long a[1000005];
long long ypa(long long x)
{
	long long t=0;
	while(x!=0)
	{
		t+=x%10;
		x/=10;
	}
	return t;
}
int main()
{
	long long g=0,n;
	scanf("%lld",&n);
	for (long long i=1;i<=999;i++)
	{
		long long s=i;
		while(s<=1000000000000000)
		{
			a[g++]=s;
			s=s*10+9;
		}
	}
	sort(a,a+g);
	g=unique(a,a+g)-a;
	for (long long i=0;i<g;i++)
	{
		bool f=1;
		for(long long j=i+1;j<g&&f;j++)
		{
			long long x=ypa(a[i]),y=ypa(a[j]);
			if (a[i]*y>a[j]*x)
			{
				f=0;
			}
		}
		if(f&&n)
		{
			printf("%lld\n", a[i]);
			n--;
		}
	}
	return 0;
}