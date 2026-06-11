/*
* @Author: wxyww
* @Date: 2020-03-15 20:59:58
* @Last Modified time: 2020-03-15 21:17:16
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1010;
#define pi pair<int,int>
ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int d[N],x[N],y[N];
int main() {
	int n = read();
	int cnt1 = 0,cnt0 = 0;
	for(int i = 1;i <= n;++i) {
		x[i] = read(),y[i] = read();
		if((x[i] + y[i]) & 1) cnt1++;
		else cnt0++;
		if(cnt0 && cnt1) {
			puts("-1");return 0;
		}
	}
	int m = 0;
	for(int i = 30;i >= 0;--i) d[++m] = 1 << i;

	if(cnt0) d[++m] = 1;

	printf("%d\n",m);
	for(int i = 1;i <= m;++i) printf("%d ",d[i]);
	puts("");
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= m;++j) {
			if(abs(x[i]) > abs(y[i])) {
				if(x[i] > 0) {x[i] -= d[j];	printf("R");}
				else {x[i] += d[j];printf("L");}
			}
			else {
				if(y[i] > 0) {y[i] -= d[j];printf("U");}
				else {y[i] += d[j];printf("D");}
			}
		}
		// printf("%d %d\n",x[i],y[i]);
		puts("");
	}

	return 0;
}