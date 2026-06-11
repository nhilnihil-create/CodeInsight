#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[114514];
int x,y,n;
int main(){
	scanf("%s",s+1);
	x=y=n=strlen(s+1);
	for(int i=1;i<=n;++i)if(s[i]=='1')x=min(x,max(i-1,n-i));else
	y=min(y,max(i-1,n-i));
	printf("%d",max(x,y));
	return 0;
}