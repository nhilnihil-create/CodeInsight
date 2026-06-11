#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+9;
int main(){
	int a[maxn],b[maxn],h,w;
	int n;
	scanf("%d",&n);
	scanf("%d%d",&h,&w);
	for(int i=0;i<n;++i)
		scanf("%d%d",&a[i],&b[i]);
	
	int ans=0;
	for(int i=0;i<n;++i)
		if(h<=a[i]&&w<=b[i])
			ans+=1;
	
	printf("%d",ans);
	return 0;
}
