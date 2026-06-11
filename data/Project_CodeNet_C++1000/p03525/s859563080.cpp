#include <map>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

int n,a;
int cnt[250] = {0};
int q1[250] = {0},q2[250] = {0},h1 = 0,h2 = 0;
int q[250] = {0},h = 0;
int ans,maxn = 0;

int main(){
	scanf("%d",&n); cnt[0] = 1;
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a);
		cnt[a] ++;
	}
	for(int i = 0;i <= 12;i ++){
		if(cnt[i] >= 3){
			printf("0\n");
			return 0;
		}
		if(cnt[i] == 1) q1[++ h1] = i;
		if(cnt[i] == 2){
			q2[++ h2] = i;
			q2[++ h2] = 24 - i;
		}
	}
	for(int i = 0;i < (1 << (h1 + 1));i += 2){
		h = 0; ans = 25;
		for(int j = 1;j <= h1;j ++){
			if(i & (1 << j)) q[++ h] = q1[j];
			else q[++ h] = 24 - q1[j];
		}
		for(int j = 1;j <= h2;j ++) q[++ h] = q2[j];
		q[++ h] = 24;
		sort(q + 1,q + 1 + h);
		for(int i = 2;i <= h;i ++) ans = min(ans,q[i] - q[i - 1]);
		maxn = max(maxn,ans);
	}
	printf("%d\n",maxn);
	return 0;
}