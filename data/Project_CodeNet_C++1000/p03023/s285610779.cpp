#include<bits/stdc++.h>

using namespace std;

int n,ans;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n-2;++i) ans+=180;
	printf("%d\n",ans);
	
	return 0;
}
			