#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n<1200)printf("ABC\n");
	else{
		if(n>=1200&&n<2800)printf("ARC\n");
		else printf("AGC\n");
	}
	return 0;
}
