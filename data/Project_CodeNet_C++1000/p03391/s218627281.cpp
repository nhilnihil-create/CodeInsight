#include <stdio.h>

int N,a,b;

int main()
{
	scanf ("%d",&N);
	long long s = 0, mn = 0x7fffffff; bool ed = true;
	for (int i=0;i<N;i++){
		scanf ("%d %d",&a,&b);
		s += a;

		if (a > b){
			if (mn > b)
				mn = b;
		}
		if (a != b) ed = false;
	}
	printf ("%lld\n",ed?0:s-mn);

	return 0;
}