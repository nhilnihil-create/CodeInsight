#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,i,c=0;
	char s[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%c",&s[i]);
		if(s[i]=='Y') c=1;
	}
	if(c==1) printf("Four\n");
	else printf("Three\n");
	return 0;
}
