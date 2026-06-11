#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n<=9){
		for(int i=0; ++i<=n; printf("%d\n",i));
		return 0;
	}
	for(int i=0; ++i<=9; printf("%d\n",i));
	n-=8;
	long long bas=1;
	for(int i=1; n&&i<=10; ++i){
		for(int j=9; ++j<(i-1)*10&&--n; printf("%d%lld\n",j,bas-1));
		bas*=10;
		if(!n)
			break;
		for(int j=max(i-2,0); ++j<10&&--n; printf("%d%lld\n",j,bas-1));
	}
	for(int i=11; n&&i<=13; ++i,bas*=10)
		for(int j=9; ++j<100&&--n; printf("%d%lld\n",j,bas-1));
	bas/=10;
	for(int i=13; n; ++i){
		for(int j=99; ++j<(i-2)*10&&--n; printf("%d%lld\n",j,bas-1));
		bas*=10;
		if(!n)
			break;
		for(int j=max(i-3,0); ++j<100&&--n; printf("%d%lld\n",j,bas-1));
	}
	return 0;
}