#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	char s[4];
	int i,c=0;
	for(i=0;i<4;i++){
		scanf("%c",&s[i]);
		if(s[i]=='+') c++;
		if(s[i]=='-') c--;
	}
	printf("%d\n",c);
	return 0;
}
