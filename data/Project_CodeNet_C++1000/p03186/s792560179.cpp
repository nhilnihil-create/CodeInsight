#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b,c;
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
  	printf("%lld",b+min(a+b+1,c));
  	return 0;
}