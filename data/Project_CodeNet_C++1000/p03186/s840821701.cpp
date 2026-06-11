#include<bits/stdc++.h>

using namespace std;

int a,b,c,ans;

int main(){
	scanf("%d%d%d",&a,&b,&c);
	ans=b; a+=b;
	ans+=min(c,a+1);
	printf("%d\n",ans);
	
	return 0;
}
			