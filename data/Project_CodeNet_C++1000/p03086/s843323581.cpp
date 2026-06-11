#include <stdio.h>
char a[15];
int main(){
	int ans = 0;
	scanf("%s",a);
	for(int i=0;a[i]!=0;i++){
		for(int j=i;a[j]!=0;j++){
			bool isACGT = true;
			for(int k=i;k<=j;k++){
				if(a[k]!='A'&&a[k]!='C'&&a[k]!='G'&&a[k]!='T'){
					isACGT = false;
				}
			}
			if(isACGT) ans = ans > j-i+1 ? ans : j-i+1;
		}
	}
	printf("%d\n",ans);
}