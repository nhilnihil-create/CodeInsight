
#include <stdio.h>
int main(){
	int i, j , k, area;
	scanf("%d %d %d", &i, &j , &k);
	if(i > j && i >> k){
		area = j * k / 2;
	}else if (j > i && j > k){
		area = i * k / 2;
	}else{
		area = i * j /2;
	}
printf("%d", area);
return 0;
}