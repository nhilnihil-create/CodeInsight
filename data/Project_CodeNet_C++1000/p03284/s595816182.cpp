#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 500001
int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d\n", N % K != 0);
	return 0;
}