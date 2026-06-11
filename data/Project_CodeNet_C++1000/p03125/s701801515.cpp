#include <stdio.h>
int main(){
	//A = *2
	//B = +k
	//N test cases
	int N, k;	//N divisor B	
	scanf("%d %d", &N, &k);
	
	if(k%N==0){	//kalo b bisa dibagi a, jumlahkan
		printf("%d", k+N);
	}
	else {		//kalo ga kurangin
		printf("%d", k-N);
	}
	
	return 0;
}