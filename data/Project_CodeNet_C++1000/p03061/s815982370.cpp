#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n;
int a[N], l[N], r[N];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i ++ ) l[i] = gcd(l[i - 1], a[i]);
	for (int i = n; i >= 1; i -- ) r[i] = gcd(r[i + 1], a[i]);
	
	int res = 0;
	for (int i = 1; i <= n; i ++ ) res = max(res, gcd(l[i - 1], r[i + 1]));
	printf("%d\n", res);
    return 0;
}