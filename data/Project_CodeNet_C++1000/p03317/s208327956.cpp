#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
#define ABS(x) (x>0?x:-(x))
#define INF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

typedef long long int lli;

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void ll_swap(lli* a, lli* b)
{
    lli tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int gcd(int a, int b)
{
    if (a < b)
        swap(&a, &b);

    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

long power(long x, int n) {
    long ans = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            ans = ans * x;
        }
        x = x * x;
        n >>= 1;
    }
    return ans;
}

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
		printf("res:%lld a:%lld\n", res,a);
	}
	return res;
}


lli comb(lli n, lli r)
{
    if (n == 0)
        return 0;

    if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return (comb(n - 1, r - 1) + comb(n - 1, r));
}

/*
#define MAX 100000
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
*/

int main()
{
    int N, K;
    int A[100000];

    scanf("%d%d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    int a;

    if ((N - K) % (K - 1) == 0)
        a = 0;
    else
        a = 1;

    printf("%d", a+(N-K)/(K - 1) + 1);
}

