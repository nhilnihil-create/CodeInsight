#include <stdio.h>
int n;
int cnt_div(int x){
	int cnt = 2;
	for(int i=3;i<x;i+=2){
		if(x%i==0) cnt ++;
	}
	return cnt;
}
int main(){
	int cnt = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=2){
		if(cnt_div(i)==8){
			cnt++;
		}
	}
	printf("%d\n",cnt);
}