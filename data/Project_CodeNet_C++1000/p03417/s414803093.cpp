#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef long long ll;
#define my_abs(n) (n > 0 ? (n) : -(n))
#define rep(i,a,b) for(int i=a;i<b;i++)
ll N, M;
int main() {
	scanf("%lld %lld", &N, &M);
	printf("%lld", my_abs((N - 2) * (M - 2)));
	return 0;
}