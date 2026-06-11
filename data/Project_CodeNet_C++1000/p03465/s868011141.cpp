#include <bits/stdc++.h>
#define ri register int
#define N 2010
using namespace std;

int n,a[N];
bitset <4000003> f;
int sum;


int gi(){
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9');
	int res=ch^48;
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=(res<<3)+(res<<1)+(ch^48);
	return res;
}


int main(){
	//freopen("mid.in","r",stdin);
	//freopen("mid.out","w",stdout);
	f.reset();
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		a[i]=gi();
		sum+=a[i];
		f|=f<<a[i];
		f.set(a[i]); 
	}
	for(ri j=(sum+1)/2;j<=sum;++j){
		if(f[j]){
			printf("%d",j);
			return 0;
		}
	}
	return 0;
}