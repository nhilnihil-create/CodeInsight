#include <stdio.h>

int main(){
	int a,b;
	int flag  = 1;
	scanf("%d %d",&a,&b);		
	char s[a+b+5];
	scanf("%s",s);
	s[a] != '-' ? flag = 0 : flag  = 1;
	for(int i=0;s[i]!='\0';i++){
			if(i!=a){
				if(s[i]<'0' || s[i]>'9'){
					flag = 0;
				}
			
			}
		}
		flag==1 ? puts("Yes") : puts("No");
 	return 0;
}