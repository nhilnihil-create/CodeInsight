#include<stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	char s[a+b+3];
	int n=a+b+1;
	scanf("%s", s);
	int ctrnum=0, ctrh=0;
	for(int i=0; i<n; i++){
		if(s[i]>='0'&&s[i]<='9'){
			ctrnum++;
		}
		if(s[i]=='-'){
			ctrh++;
		}
	}

	if(ctrnum>=2 && s[a]=='-' && ctrh==1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}