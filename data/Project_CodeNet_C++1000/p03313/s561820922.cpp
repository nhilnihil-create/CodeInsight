#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_m 262144
using namespace std;
int a[max_m],b[max_m];
void deal(int x,int y){
	if(a[y]>a[x]){
		b[x]=max(a[x],b[y]);
		a[x]=a[y];
	}
	else
		a[y]>b[x]&&(b[x]=a[y]);
//	printf("*%d %d %d\n",x,a[x],b[x]);
}
int maxify(int&x,const int&y){
	return y>x?(x=y):x;
}
int main(){
	int n,m;
	scanf("%d",&n);
	m=1<<n;
	for(int i=-1; ++i<m; scanf("%d",a+i));
	memset(b,0,sizeof(b));
	for(int i=1,x=1; (x<<=1)<=m; i=x)
		for(int j=0; j<m; j+=x)
			for(int k=0; k<i; ++k)
				deal(j|i|k,j|k);
	for(int i=0,ans=0; ++i<m; printf("%d\n",maxify(ans,a[i]+b[i])));
	return 0;
}