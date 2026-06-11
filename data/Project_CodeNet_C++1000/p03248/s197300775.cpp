#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define reg register
using namespace std;
typedef long long ll;
const int MN=1e5+5;
int n,x[MN],y[MN];
char ch[MN];
int main(){
	scanf("%s",ch+1);n=strlen(ch+1);
	if((ch[n]^48)||!(ch[1]^48))return 0*puts("-1");
	for(reg int i=1;i<=(n>>1);i++)if(ch[i]^ch[n-i])return 0*puts("-1");
	reg int pre=1;
	for(reg int i=2;i<=n;i++)if(ch[i]^48)for(;pre<i;pre++)printf("%d %d\n",pre,i);
	printf("%d %d\n",n-1,n);
	return 0;
}