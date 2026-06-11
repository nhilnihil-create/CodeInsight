#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
#define LL long long
const LL inf = 0x3f3f3f3f3f3f3f3f;

LL x[1001],y[1001];

vector<LL>len;

LL dir[4][2]={0,1,0,-1,1,0,-1,0};
char s[4]={'U','D','R','L'};


LL mht(LL x,LL y,LL a,LL b)
{
	return abs(x-a)+abs(y-b);
}

int main()
{
	LL n;
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(LL i=2;i<=n;i++){
		if(((x[i]^y[i])&1)!=((x[1]^y[1])&1)){
			printf("-1\n");
			return 0;
		}
	}
	for(LL i=30;i>=0;i--){
		len.push_back(1LL<<i);
	}
	if(((x[1]^y[1])&1)==0){
		len.push_back(1);
	}
	printf("%lld\n",(LL)len.size());
	for(LL i=0;i<len.size();i++){
		if(i) printf(" ");
		printf("%lld",len[i]);
	}
	printf("\n");
	for(LL i=1;i<=n;i++){
		LL xx=0,yy=0;
		for(LL j=0;j<len.size();j++){
			LL Min=inf;
			LL pos=-1;
			for(LL k=0;k<4;k++){
				LL l=mht(xx+dir[k][0]*len[j],yy+dir[k][1]*len[j],x[i],y[i]);
				if(Min>l){
					Min=l;
					pos=k;
				}
			}
			printf("%c",s[pos]);
			xx+=dir[pos][0]*len[j];
			yy+=dir[pos][1]*len[j];
		}
		printf("\n");
	}


}



