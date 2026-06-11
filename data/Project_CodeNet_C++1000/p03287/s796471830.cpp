#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 2 * N;

int n, m;
int a[N];
LL s[N];
map<int, int> cnt;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
	
	cnt[0] = 1;
	LL res = 0;
	for (int i = 1; i <= n; i ++ ) res += cnt[s[i] % m] ++ ;
	printf("%lld\n", res);
    return 0;
}