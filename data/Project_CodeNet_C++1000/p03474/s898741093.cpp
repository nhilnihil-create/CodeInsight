#include <stdio.h>
int main(){
	int A, B;
	char zip[20];
	bool valid= true; //kita anggap semua postal code awalnya valid 
	
	scanf("%d %d", &A, &B);
	scanf("%s",zip);
	
	if(zip[A]!='-'){//269-6650|| cek apakah di index A itu bukan -
	valid= false; //jika bukan, valid menjadi false
}
	for (int i=0; zip[i] !='\0'; i++){
		if(i !=A){//cek index selain a
			if (zip[i]<'0'||zip[i]>'9'){//jika dia di luar rentang 0--9
				valid=false;//valid menjadi false
				break;//keluar dari loop
			}
		}
	}	
//jika valid adalah true, puts yes, selain itu no	
	
	(valid)? puts("Yes"): puts("No");
	
	
	return 0;
}