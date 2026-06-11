#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

using namespace std;

typedef long long int lli;

int gcd(int a, int b) {
	return b != 0 ? gcd(b, a%b) : a;
}
lli gcd(lli a, lli b) {
	return b != 0 ? gcd(b, a%b) : a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
lli lcm(lli a, lli b) {
	return a * b / gcd(a, b);
}

#define N_MAX 1000000
#define MOD 1000000007

int N, Q;
char S[N_MAX + 10];
int num[3][N_MAX + 10];
void solv2(int k)
{
	lli ret = 0;
	int left = -1, right = -1;
	for (int i = 0; i < N; i++) {
		if ('D' == S[i]) {
			left = i;
			break;
		}
	}

	if (-1 == left) {
		printf("0\n");
		return;
	}

	lli sum = 0;
	for (right = left; right < min(N, left + k); right++) {
		if ('C' != S[right]) continue;
		sum += (lli)(num[1][right + 1] - num[1][left + 1]);
	}
	ret += sum;

	for (left = left + 1; left < N; left++, right = min(N, right + 1)) {
		if ('M' == S[left]) {
			sum -= (lli)(num[2][right] - num[2][left + 1]);
		}
		if ('C' == S[right]) {
			sum += (lli)(num[1][right] - num[1][left + 1]);
		}
		if ('D' == S[left]) {
			ret += sum;
		}
	}

	printf("%lld\n", ret);
}

void solv()
{
	scanf("%d%s%d", &N, S, &Q);

	num[0][0] = num[1][0] = num[2][0] = 0;
	for (int i = 1; i <= N; i++) {
		num[0][i] = num[0][i - 1] + ('D' == S[i - 1] ? 1 : 0);
		num[1][i] = num[1][i - 1] + ('M' == S[i - 1] ? 1 : 0);
		num[2][i] = num[2][i - 1] + ('C' == S[i - 1] ? 1 : 0);
	}
	num[1][N + 1] = num[1][N];

	for (int i = 0; i < Q; i++) {
		int k; scanf("%d", &k);
		solv2(k);
	}

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}
