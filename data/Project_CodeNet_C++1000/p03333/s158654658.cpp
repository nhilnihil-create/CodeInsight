#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

typedef long long ll;
ll n, s, a[N], b[N];
int main()
{
	ll i;
	cin >> n;
	for (i = 1; i <= n; i++) scanf("%lld %lld", &a[i], &b[i]);
	sort(a, a + n + 1);
	sort(b, b + n + 1);
	for (i = 0; i <= n; i++) s += max(0LL, a[i] - b[n - i]) * 2;
    cout << s << endl;
    return 0;
}