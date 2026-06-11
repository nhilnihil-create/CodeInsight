#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100010

long long x[MAXN], v[MAXN];
long long shun[MAXN], ni[MAXN];
long long mx1[MAXN], mx2[MAXN];

int main() {
	long long n, c; cin >> n >> c;
	memset(shun, 0, sizeof(shun));
	memset(ni, 0, sizeof(ni));
	for (int i = 1; i <= n; i ++) {
		cin >> x[i] >> v[i];
		shun[i] = shun[i-1] + v[i];
	}
	for (int i = n; i > 0; i --)
		ni[i] = ni[i+1] + v[i];
		
	long long ans = max(0LL, max(shun[n]-x[n], ni[1]-c+x[1]));
	memset(mx1, 0, sizeof(mx1));
	memset(mx2, 0, sizeof(mx2));
	for (int i = 1; i <= n; i ++) mx1[i] = max(mx1[i-1], shun[i] - 2*x[i]);
	for (int i = n; i > 0; i --) mx2[i] = max(mx2[i+1], ni[i] - 2*(c-x[i]));
	
	for (int i = 1; i <= n; i ++) 
		ans = max(ans, shun[i]-x[i]+mx2[i+1]);
	for (int i = n; i > 0; i --) 
		ans = max(ans, ni[i]-c+x[i]+mx1[i-1]);
		
	cout << ans << endl;	
	return 0;	
}