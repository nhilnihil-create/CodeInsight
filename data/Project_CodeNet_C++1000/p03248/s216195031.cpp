#include <cstdio>
#include <cstring>
#define max_n 100000
using namespace std;
char s[max_n+1];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	if(s[1]=='0'||s[n]=='1'){
		puts("-1");
		return 0;
	}
	for(int i=n; --i; )
		if(s[i]!=s[n-i]){
			puts("-1");
			return 0;
		}
	for(int i=1,r=1; ++i<=n; s[i-1]=='1'&&(r=i))
		printf("%d %d\n",r,i);
	return 0;
}