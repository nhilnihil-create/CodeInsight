#include <stdio.h>
int main()
{
	int A,P ;
	scanf("%d%d", &A,&P );
	A=3*A;//jumlah Apel berubah jadi jumlah potongan apel dari A
	P=P+A;//jumlah potongan apel dari input berubah jadi jumlah potongan apel secara keseluruhan dari Input dan A
	printf("%d\n",P/2);
	return 0;

}