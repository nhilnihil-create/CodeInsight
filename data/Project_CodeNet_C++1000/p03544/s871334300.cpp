#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<iostream>
#define R(i, n) for(int i = 0; i < n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d",  &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define P(a) printf("%d", a)
#define PL(a) printf("%lld", a);
#define PY printf("%s", "Yes");
#define PN printf("%s", "No");
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> IR;

int main(){
	int n;
	S(n);
	vector<ll> dp(n + 1);
	dp[0] = 2;
	dp[1] = 1;
	for(int i = 2; i <= n; i++) dp[i] = dp[i -1] + dp[i -2];
	PL(dp[n]);

}