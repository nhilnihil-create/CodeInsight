#include<cstdio>
using namespace std;
int index[1<<19];
int xor_sum[1<<19];
int ans[1<<19];
bool vis[1<<19];
int main(){
	int m,k;
	scanf("%d %d",&m,&k);
	if(m==0){
		if(k==0)
			printf("0 0\n");		
		else
			printf("-1\n");
		return 0;
	}else if(m==1){
		if(k==0)
			printf("0 0 1 1\n");		
		else
			printf("-1\n");
		return 0;
	}else{
		if(k>((1<<m)-1))
			printf("-1\n");
		else{
			for(int i=0;i<=((1<<m)-1);i++)
				if(i!=k)
					printf("%d ",i);
			printf("%d ",k);
			for(int i=((1<<m)-1);i>=0;i--)
				if(i!=k)
					printf("%d ",i);
			printf("%d ",k);	
		}
	}
	return 0;	
}