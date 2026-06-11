#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;

ll n, b, s, a[N], d[N];
int main() {
	int i, j, k;
	cin >> n;
	for(i=0; i<n; i++) scanf("%lld", &a[i]);
	for(i=0; i<n; i++) scanf("%lld", &b), d[i] = a[i] - b;
	sort(d, d+n);
	for(i=0; i<n && d[i]<0; i++) s += d[i];
	for(j=n-1, k=0; j>=0 && s<0; j--, k++) s += d[j];
	cout << (s<0 ? -1 : i + k);
	return 0;
}