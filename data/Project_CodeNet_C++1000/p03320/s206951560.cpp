#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
using namespace std;

int n;

int sum(long long x){
	int ret=0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	long long x=1ll,d=1ll;
	while(n--){
		printf("%lld\n",x);
		if((x+d)*sum(x+d*2)>(x+d*2)*sum(x+d)) d*=10;
		x+=d;
	}
	return 0;
}

/*
数据不清空，爆零两行泪
读题不认真，爆零两行泪
分析不仔细，爆零两行泪
建树不构造，爆零两行泪
变量不统一，爆零两行泪
边界不算清，爆零两行泪
数组不开大，爆零两行泪
*/