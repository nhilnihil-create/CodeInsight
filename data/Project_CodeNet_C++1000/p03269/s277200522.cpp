#include<stdio.h>
#include<string.h>
char s[100010],*p;
int main(){
	int L,r,i,w,n,m;
	scanf("%d",&L);
	for(r=0;1<<r<=L;r++);
	r--;
	n=r+1;
	m=0;
	p=s;
	for(i=1;i<=r;i++){
		sprintf(p,"%d %d %d\n",i,i+1,1<<(i-1));
		p+=strlen(p);
		sprintf(p,"%d %d %d\n",i,i+1,0);
		p+=strlen(p);
		m+=2;
	}
	w=1<<r;
	for(i=r;i>0;i--){
		if(L>>(i-1)&1){
			sprintf(p,"%d %d %d\n",i,r+1,w);
			p+=strlen(p);
			m++;
			w|=1<<(i-1);
		}
	}
	printf("%d %d\n%s",n,m,s);
}