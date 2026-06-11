#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for ( int i =0; i < n ; i ++)
int N, M;
vector<int> x, d;
int main()
{
	scanf("%d %d", &N, &M);
	printf("%f", (double)N / M);
}