#include<cstdio>
using namespace std;
#define LL long long
LL s(LL x){
	LL ret=0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	return ret;
}
int main(){
	int k;
	scanf("%d",&k);
	LL per=1;
	LL d=1;
	while(k--){
		printf("%lld\n",per);
		if(s(per+d)*(per+d*10)<s(per+d*10)*(per+d)){
			d*=10;
		}
		per+=d;
	}
}
