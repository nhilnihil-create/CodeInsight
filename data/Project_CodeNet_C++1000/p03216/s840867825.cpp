/*************************************************************************
  > File Name: kdmc.cpp
  > Author: PumpkinYing
  > Created Time: 2018/11/28 13:45:23
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define prii pair<int,int>
#define prdd pair<double,double>
#define rep(i,l,r) for(int i = l;i < r;i++)
#define rep_(i,l,r) for(int i = l;i <= r;i++)
typedef long long ll;

const int maxn = 1000010;
char s[maxn];

ll work(char* s,int k) {
	int n = strlen(s);
	ll cntM = 0,cntC = 0;
	ll ret = 0;
	ll tmp = 0;
	for(int i = 0;i < k;i++) {
		if(s[i] == 'M') cntM++;
		else if(s[i] == 'C') {
			cntC++;
			tmp += cntM;
		}
	}
	if(s[0] == 'D') ret += tmp;

	for(int i = 1;i < n;i++) {
		if(i+k-1 < n) {
			if(s[i+k-1] == 'M') cntM++;
			else if(s[i+k-1] == 'C') {
				cntC++;
				tmp += cntM;
			}
		}

		if(s[i-1] == 'M') {
			tmp -= cntC;
			cntM--;
		}
		else if(s[i-1] == 'C') {
			cntC--;
		}

		if(s[i] == 'D') ret += tmp;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int q;
	scanf("%d",&q);
	rep(cou,0,q) {
		int k;
		scanf("%d",&k);
		printf("%lld\n",work(s,k));
	}
	return 0;
}
