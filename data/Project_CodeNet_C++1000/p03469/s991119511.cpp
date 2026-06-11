#include <stdio.h>      
int main() {

	char tanggal[12];

	scanf("%s", &tanggal);getchar();
	tanggal[3] = '8';
	printf("%s\n", tanggal);

  

  return 0;
}
