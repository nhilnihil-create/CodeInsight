#include<bits/stdc++.h>
using namespace std;
int a[30005],n,tot;
int main(){
	scanf("%d",&n);
	if (n==3) return puts("2 5 63"),0;
	for (int i=1;i<=30000;i++)
		if (i%2==0||i%3==0)
			a[++tot]=i;
	for (;;){
		random_shuffle(a+1,a+(n==3?100:tot)+1);
		int have2=0,have3=0,sum=0;
		for (int j=1;j<=n;j++){
			sum=(sum+a[j])%6;
			if (a[j]%2) have2=1;
			if (a[j]%3) have3=1;
		}
		if (!sum&&have2&&have3){
			for (int j=1;j<=n;j++)
				printf("%d ",a[j]);
			puts("");
			exit(0);
		}
	}
}