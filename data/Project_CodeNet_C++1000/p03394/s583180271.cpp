#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n==3) printf("2 5 63");
	else printf("2 3 5 ");
	n-=3;
	int sum=2+3+5;
	for(int i=6;n>0;i++){
		if(i%2==0||i%3==0||i%5==0){
			sum+=i;
			while(n==2&&(!(i%2==0||i%3==0||i%5==0)||(sum%2!=0&&sum%3!=0&&sum%5!=0))){
				i++;
				sum++;
			}
			n--;
			if(n==0){
				while(sum%2!=0||sum%3!=0||sum%5!=0){
					i++;
					sum++;
				}
			}
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}