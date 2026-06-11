#include <map>
#include <list>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

int cal[13] = {0};
int val[26] = {0},vc;
int a[55] = {0};
int n,tmp,maxn = 0;

int main(){
	scanf("%d",&n);
	for(register int i = 0;i < n;i ++){
		scanf("%d",&a[i]);
		cal[a[i]] ++;
		if(cal[a[i]] >= 3 || cal[12] >= 2 || cal[0] >= 1){
			printf("0\n");
			return 0;
		}
	}
	for(register int i = 0;i < (1 << 22);i ++){
		memset(val,0,sizeof(val)); vc = 0;
		for(register int j = 1;j <= 11;j ++){
			if(cal[j] == 0) continue;
			if(cal[j] == 1){
				if((i >> (j - 1 + j - 1)) & 1) val[++ vc] = j;
				else val[++ vc] = 24 - j;
			}
			if(cal[j] == 2){
				if((i >> (j - 1 + j - 1)) & 1) val[++ vc] = j;
				else val[++ vc] = 24 - j;
				if((i >> (j - 1 + j)) & 1) val[++ vc] = j;
				else val[++ vc] = 24 - j;
			}
		}
		if(cal[12]) val[++ vc] = 12;
		val[++ vc] = 24;
		sort(val + 1,val + 1 + vc);
		tmp = 24;
		for(register int j = vc;j >= 1;j --) tmp = min(tmp,val[j] - val[j - 1]);
		maxn = max(maxn,tmp);
	}
	printf("%d\n",maxn);
	return 0;
}