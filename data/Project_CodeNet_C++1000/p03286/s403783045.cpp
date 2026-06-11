#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 1000000000
int main(void) {
	ll N, a = 1;
	scanf("%lld", &N);
	deque<int> ans;
	if (N == 0)printf("%d\n", 0);
	while (N) {
		if(abs(N) & abs(a))ans.push_front(1), N -= a;
		else ans.push_front(0);
		a *= -2;
	}
	for (auto v : ans)printf("%d", v);
	return 0;
}