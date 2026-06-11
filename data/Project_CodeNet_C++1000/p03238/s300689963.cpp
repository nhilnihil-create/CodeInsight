#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define i_cin(X) scanf("%d", &X)
#define i_cin2(X,Y) scanf("%d %d",&X,&Y)
#define l_cin(X) scanf("%ld",&X)
#define s_cin(X) scanf("%s",%X)

#define  i_cout(X) printf("%d\n",X)
#define  l_cout(X) printf("%ld\n",X)
#define  s_cout(X) printf("%s\n",X)
#define  ll_cout(X) printf("%lld\n",X)

int main(void) {
	int a, b;
	i_cin(a);
	if (a == 1) {
		s_cout("Hello World"); return 0;
	}
	i_cin2(a, b);
	i_cout(a + b);
	return 0;
}