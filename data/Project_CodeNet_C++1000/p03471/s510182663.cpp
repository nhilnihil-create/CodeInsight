#include<bits/stdc++.h>
using namespace std;
int n,v;
int main(){
	scanf("%d%d",&n,&v);
	for (int i=0;i<=n;i++)
		for (int j=0;j+i<=n;j++)
			if (i*10000+j*5000+(n-i-j)*1000==v)
				return printf("%d %d %d",i,j,n-i-j),0;
	puts("-1 -1 -1"); 
} 
