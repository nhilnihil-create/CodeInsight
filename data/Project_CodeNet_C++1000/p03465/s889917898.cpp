#include<bits/stdc++.h>
using namespace std;
int n,a,sum;
bitset<4000003>f;
int main(){
	f[0]=1;
	scanf("%d",&n);
	while (n--){
		scanf("%d",&a);
		f|=f<<a,sum+=a;
	}
	for (register int i=(sum+1)/2;i<=sum;i++)
	 if (f[i]) return printf("%d\n",i),0;
}