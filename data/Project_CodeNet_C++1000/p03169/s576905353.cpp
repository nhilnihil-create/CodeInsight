#include<iostream>
using namespace std;

int n,x,y,z;
double a[307],dp[300][300][300];

double dfs(int x,int y,int z){
	if(x==0&&y==0&&z==0)return 0;
	if(dp[x][y][z]!=0)return dp[x][y][z];
	double ans=n/(double)(x+y+z);
	if(x>0)ans+=(double)x/(double)(x+y+z)*dfs(x-1,y,z);
	if(y>0)ans+=(double)y/(double)(x+y+z)*dfs(x+1,y-1,z);
	if(z>0)ans+=(double)z/(double)(x+y+z)*dfs(x,y+1,z-1);
	return dp[x][y][z]=ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
		if(a[i]==1){
			x++;
		}
		else if(a[i]==2){
			y++;
		}
		else{
			z++;
		}
	}
	printf("%.15f\n",dfs(x,y,z));
}