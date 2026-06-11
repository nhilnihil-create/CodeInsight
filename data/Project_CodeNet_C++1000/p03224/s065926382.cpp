#include<bits/stdc++.h>
#define LL long long
#define RG register
#define R RG int
using namespace std;
vector<int>c[400];
int main(){
	R n,now=0;
	cin>>n;
	R d=(1+sqrt(1+8*n))/2;
	if(d*(d-1)!=2*n)return puts("No"),0;
	printf("Yes\n%d\n",d);
	for(R i=1;i<=d;++i){
		printf("%d",d-1);
		for(R j=1;j<i;++j)
			printf(" %d",c[j][c[j].size()-1]),c[j].pop_back();
		for(R j=i;j<d;++j)
			printf(" %d",++now),c[i].push_back(now);
		puts("");
	}
	return 0;
}