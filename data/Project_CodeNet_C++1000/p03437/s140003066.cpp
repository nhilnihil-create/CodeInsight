#include <algorithm>
#include <cstdio>

using namespace std ;

int main ()
{
	long long x , y ;
	scanf("%lld%lld",&x,&y);
	if ( x%y==0 ) puts("-1");
	else printf("%lld\n",x);
	return 0 ;
}