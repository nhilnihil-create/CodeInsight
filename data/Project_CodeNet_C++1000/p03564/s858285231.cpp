#include<stdio.h>

int main()
{
	int n, m;
	int ans = 1;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		if(ans <= m){
			ans*= 2;
		}else{
			ans+=m;
		}
	}
	printf("%d\n", ans);
}