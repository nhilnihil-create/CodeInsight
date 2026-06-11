#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,k;
	scanf("%d%d",&m,&k);
	m = (1<<m);
	//printf("%d\n",m);
	if(k>=m){
		printf("-1\n");
	}
	else{
		if(m==2){
			if(k==0){
				printf("0 0 1 1\n");
			}
			else printf("-1\n");
			return 0;
		}
		for(int i=0;i<m;i++){
			if(i!=k)printf("%d ",i);
		}
		printf("%d ",k);
		for(int i=m-1;i>=0;i--){
			if(i!=k)printf("%d ",i);
		}
		printf("%d\n",k);
	}
}
