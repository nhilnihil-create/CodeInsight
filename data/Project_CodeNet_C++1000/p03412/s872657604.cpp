#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=200005;
const int P=998244353;

int n;
int a[N],b[N];
int L;
int ans;

#define f(x) ((x)&(L-1))

inline bool cmp(int x,int y){return f(x)<f(y);}

void init(){
	int tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=0;i<=28;i++){
		
		//if(i<=2) printf("%d:\n",i);
		
		L=1<<i;
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		
		//if(i<=2) for(int j=1;j<=n;j++) printf("%d ",f(a[j])); printf("\n");
		//if(i<=2) for(int j=1;j<=n;j++) printf("%d ",f(b[j])); printf("\n");
		
		tmp=0;
		for(int j=1;j<=n;j++) tmp^=(b[j]&L);
		for(int l=1,r=n+1;l<=n;l++){
			while(f(a[l])+f(b[r-1])>=L && r>1) r--;
			
			//if(i<=2) printf("%d %d ",l,r);
			
			if(n&1) if(a[l]&L) ans^=L;
			if((n-r+1)&1) ans^=L;
			ans^=tmp;
			
			//if(i<=2) printf("- (cur:%d\n",ans);
			
		}
	}
	printf("%d\n",ans);
}

int main(){
	init();
	return 0;
}