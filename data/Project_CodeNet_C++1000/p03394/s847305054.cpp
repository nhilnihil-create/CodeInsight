#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if (n==3){
		puts("2 5 63");
		return 0;
	}
	for (int i=1;i<n;i++)
		if (i*2<=30000&&(n-i)*6<=30000&&i%3!=1&&(n-i)%2==0){
			for (int j=1;j<=i;j++)printf("%d ",j*2);
			for (int j=1;j<=n-i;j++)printf("%d ",j*6-3);
			return 0;
		}
} 