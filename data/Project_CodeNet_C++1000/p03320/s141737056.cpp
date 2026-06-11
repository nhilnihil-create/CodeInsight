#include <bits/stdc++.h>
using namespace std;
int k;
long long ans = 1,p = 1;
int cnt(long long a){
	if(a < 10)return a;
	return a%10 + cnt(a/10);
}
int main(){
	//freopen("readin.txt","r",stdin);
	scanf("%d",&k);
	for(int i = 0;i < k;i++){
		printf("%lld\n",ans);
		if((ans + p)*cnt(ans + p*10) > (ans + p*10)*cnt(ans + p))p*=10;
		ans+=p;
	}	
}