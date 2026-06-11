#include <cstdio>
#include <algorithm>
#define max_n 2000
#define INF 2147483647
using namespace std;
int a[max_n+1],t[max_n+1],b[max_n+1],c[max_n+1];
template<typename T1,typename T2>void minify(T1&x,const T2&y){
	y<x&&(x=y);
}
void cal(int mn,int n,int k,int q,int&ans){
	int bcnt=0;
	for(int l,r=1,cnt=0; r<=n; cnt=0){
		for(l=r-1; a[++l]<mn&&l<=n; );
		for(r=l-1; a[++r]>=mn&&r<=n; );
    	for(int i=l-1; ++i<r; c[++cnt]=a[i]);
    	if(cnt>=k){
    		nth_element(c+1,c+cnt-k+1,c+cnt+1);
    		for(int i=0; ++i<=cnt-k+1; b[++bcnt]=c[i]);
		}
	}
	nth_element(b+1,b+q,b+bcnt+1);
    bcnt>=q&&(minify(ans,b[q]-*min_element(b+1,b+q+1)),1);
}
int main(){
	int n,k,q,ans=INF;
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0; ++i<=n; t[i]=a[i])
		scanf("%d",a+i);
	stable_sort(t+1,t+n+1);
	for(int i=0; ++i<=n; cal(t[i],n,k,q,ans));
    printf("%d\n",ans);
    return 0;
}