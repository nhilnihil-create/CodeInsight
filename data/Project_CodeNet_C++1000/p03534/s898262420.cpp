#include<stdio.h>
#include<string.h>

char s[100005];
int main(){
	int len,i;
	int a,b,c,t;
	while(scanf("%s",s)!=EOF){
		a=0;b=0;c=0;
		len=strlen(s);
		for(i=0;i<len;i++){
			if(s[i]=='a')
				a++;
			else if(s[i]=='b')
				b++;
			else
				c++;
		}
		if(a<b){
			t=a;a=b;b=t;}
		if(a<c){
			t=a;a=c;c=t;}
		if(b<c){
			t=b;b=c;c=t;}
		
		if(a-c>=2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}