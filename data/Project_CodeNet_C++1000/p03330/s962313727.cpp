#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
int n,c,x; 
int d[34][34],t[3][34];
int main(){ 
	scanf("%d%d",&n,&c);
	for(int i=1;i<=c;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&d[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			t[(i+j)%3][x]++;
		}	
	int minn=1<<30;
	for(int i=1;i<=c;i++){
		for(int j=1;j<=c;j++){					
			if(i==j)continue;
			for(int k=1;k<=c;k++){
				if(i==k||j==k)
					continue;
				int tt=0;
				for(int l=1;l<=c;l++)tt+=d[l][i]*t[0][l];
				for(int l=1;l<=c;l++)tt+=d[l][j]*t[1][l];
				for(int l=1;l<=c;l++)tt+=d[l][k]*t[2][l];
				if(tt<minn)minn=tt;
			}
		}
	} 
	printf("%d\n",minn);
	return 0;
}