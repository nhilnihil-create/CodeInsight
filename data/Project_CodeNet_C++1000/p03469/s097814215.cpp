#include <stdio.h>

int main(){
	char date[10];
	for(int i = 0; i < 10; i++){
	scanf("%c", &date[i]);
}
	if(date[3] == '7'){
		date[3] = '8';
	}
	for(int i = 0; i < 10; i++){
	printf("%c", date[i]);
}
	return 0;
}