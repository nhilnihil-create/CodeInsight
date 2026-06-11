#include <stdio.h>

int main (){
	int batas, angka1, angka2;
	scanf ("%d %d %d", &batas, &angka1, &angka2);
	int sum =0;
	for (int i=1; i <= batas; i++){
		int hitungDigit = 0;
		int temp = i;
		
		while (temp != 0){
			hitungDigit = hitungDigit + temp%10;
			temp /= 10;
		}
		if (hitungDigit >= angka1 && hitungDigit <= angka2){
			sum += i;
		}
	}
	printf("%d\n", sum);
	
	return 0;
}