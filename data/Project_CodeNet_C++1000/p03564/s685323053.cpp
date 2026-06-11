#include<stdio.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int tot=1;
	for(int i=1; i<=n; i++){
		if((tot*2)<=(tot+k)){
		tot*=2;
		}
		else{
			tot+=k;
		}
	}
	printf("%d\n", tot);
	return 0;
}