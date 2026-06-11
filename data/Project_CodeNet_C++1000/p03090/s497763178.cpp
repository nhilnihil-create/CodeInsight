#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	scanf("%d",&n);
	int m =n*(n-1) / 2;
	m-= n/2;
	printf("%d\n",m);
	int tar = n;
	if(n%2 == 0) tar++;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j==tar-i) continue;
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}