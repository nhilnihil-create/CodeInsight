#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define mySwap(a, b) {int temp = a; a = b; b = temp;}

typedef long long ll;
const int MAXN = 1e5+10;

int preGcd[MAXN], postGcd[MAXN], num[MAXN];

int gcd(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &num[i]);
	}
	preGcd[1] = num[1];
	postGcd[n] = num[n];
	for (int i=2; i<=n; i++) {
		preGcd[i] = gcd(num[i], preGcd[i-1]);
	}
	for (int i=n-1; i>=1; i--) {
		postGcd[i] = gcd(num[i], postGcd[i+1]);
	}
	
	//int ans = max(preGcd[n], postGcd[1]);
	int ans = max(preGcd[n-1], postGcd[2]);
	for (int i=2; i<n; i++)
		ans = max(ans, gcd(preGcd[i-1], postGcd[i+1]));
	printf("%d\n", ans);
	return 0;
}