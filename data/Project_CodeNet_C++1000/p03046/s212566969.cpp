
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,k;
	scanf("%d%d",&m,&k);
	if(k==0){
		for(int i=0;i<(1<<m);i++)
			printf("%d %d ",i,i);
		printf("\n");
	}
	else if(m==1){
		if(k>=1)
			puts("-1");
		else puts("1 1 0 0");
	}
	else{
		if(k>=(1<<m))
			puts("-1");
		else{
			printf("%d ",k);
			for(int i=0;i<(1<<m);i++)
				if(i!=k)
				printf("%d ",i);
			printf("%d ",k);
			for(int i=(1<<m)-1;i>=0;i--)
				if(i!=k)
				printf("%d ",i);
		}
	}	
}