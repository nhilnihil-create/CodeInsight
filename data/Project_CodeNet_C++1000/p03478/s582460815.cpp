#include <stdio.h>

int main (){
	int x,y,z;
	int hasil = 0;
	scanf("%d %d %d", &x, &y, &z);
	for(int i = 0 ; i <= x; i++){
		int num=i;
		int temp = 0;
		while(num > 0){
			temp += num%10;
			num /= 10;
		}
		if(temp >= y && temp <=z){
			hasil += i;
		}
	}
	printf("%d",hasil);
	return 0;
}
