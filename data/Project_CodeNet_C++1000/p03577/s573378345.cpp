#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=50+2;
char str[maxn];
int main(){
	scanf("%s",str+1);
	int len=strlen(str+1);
	len-=8;
	for (int i=1;i<=len;i++) printf("%c",str[i]);
	return 0;
}