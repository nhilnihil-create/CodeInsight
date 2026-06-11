#include <stdio.h>

int main(){
int a,b;
char s[20];
bool pos = true;
scanf("%d %d",&a,&b);
scanf("%s",s);

if(s[a] != '-'){ //itu [A] karena di index 1,+1 -1 = karena di soal index 1 di awal
	pos = false;
}

for(int i = 0;s[i]!='\0';i++){ //\0 (selama dia tidak sampai ke null maka loop terus
	if(i != a){//jika karakter bukan di A maka cek(selain -)
		if(s[i]< '0' || s[i]> '9'){ //kalau bukan di rentang ini bye
		 pos = false;
		 break; //karena false break aja dari loopnya
		}
    }	
}
	//kalau benar dan tidak false print yes
	(pos) ? printf("Yes\n") : printf("No\n");
	return 0;
}