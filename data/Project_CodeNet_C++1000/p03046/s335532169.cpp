#include<bits/stdc++.h>
using namespace std;
int m,k; 
int main(){
	cin>>m>>k;
	int tmp=(1<<m)-1;
	if(m==0&&k==0){
		puts("0 0");
		return 0;
	}
	if(k<=tmp){
		if(m==1&&k==1){
			puts("-1");
			return 0;
		}
		if(!k){
			for(int i=0;i<=tmp;i++){
				printf("%d %d%c",i,i,(i==tmp)?'\n':' ');
			}
		}
		else{
			printf("0 %d 0 ",k);
			for(int i=1;i<=tmp;i++){
				if(i==k) continue;
				printf("%d ",i);
			}
			printf("%d ",k);
			for(int i=tmp;i>=1;i--){
				if(i==k) continue;
				printf("%d ",i);
			}putchar('\n');
		}
	}
	else{
		puts("-1");
	}
	return 0;
}
