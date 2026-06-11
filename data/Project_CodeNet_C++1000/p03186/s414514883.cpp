#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",min(c,a+b+1)+b);
}
