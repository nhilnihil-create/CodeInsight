#include <stdio.h>
int main(){
int a,b,c;
scanf("%d %d %d",&a,&b,&c);
int ans=0;
for (int i=1;i<=a;i++){
	int temp = i;
	int total = 0;
	while (temp>0){
		total += temp %10;
		temp /=10;
	}
	if (total >=b&& total <=c){
		ans +=i;
	}
}

printf("%d\n",ans);
return 0;
}
