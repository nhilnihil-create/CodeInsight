#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=100005;

int n,now,last;
char s[N];

int main(){
	int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	if (s[n]!='0'||s[1]!='1'){
		printf("-1\n");
		return 0;
	}
	for (i=1;i<n;i++) if (s[i]!=s[n-i]){
		printf("-1\n");
		return 0;
	}
	now=1; last=1;
	for (i=2;i<=n;i++){
		if (s[i]=='1'){
			for (j=last;j<=now;j++) printf("%d %d\n",j,i);
			now=last=i;
			continue;
		}
		now++;
	}
	printf("%d %d\n",n-1,n);
	return 0;
} 