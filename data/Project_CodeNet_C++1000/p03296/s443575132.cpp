#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define i_cin(X) scanf("%d", &X)
#define i_cin2(X,Y) scanf("%d %d",&X,&Y)
#define i_cin3(X,Y,Z) scanf("%d %d %d",&X,&Y,&Z)
#define l_cin(X) scanf("%ld",&X)
#define s_cin(X) scanf("%s",&X)


#define  i_cout(X) printf("%d\n",X)
#define  i_cout2(X,Y) printf("%d %d\n",X,Y)
#define  l_cout(X) printf("%ld\n",X)
#define  s_cout(X) printf("%s\n",X)
#define  ll_cout(X) printf("%lld\n",X)

int i_cins(int n, int* A);

int main(void) {
	int   N, A[101],i,cnt=0;
	i_cin(N);
	i_cins(N, A);
	for (i = 0;i < N-1;i++)
	{
		if (A[i] == A[i + 1]) {
			cnt++; A[i + 1] = 10001;
		}
	}
	i_cout(cnt);
	return 0;
}

int i_cins(int n, int* A) {
	int i;
	for (i = 0; i < n; i++) 
		i_cin(*(A + i));
	return 0;
}
