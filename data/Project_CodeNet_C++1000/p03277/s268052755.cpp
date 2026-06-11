#include<iostream>
#include<algorithm>
#include<cstring>
#define lowbit(x) (x)&(-x)
#define ll long long 
using namespace std;

const int maxn = 1e5 + 100;
ll c[maxn * 10]; int a[maxn]; ll N; ll sum[maxn * 10];

void add(int x)
{
	while (x <= N * 2)
	{
		c[x] += 1; x += lowbit(x);
	}
}

ll getsum(int x)
{
	ll sum = 0;
	while (x >= 1)
	{
		sum += c[x]; x -= lowbit(x);
	}
	return sum;
}

bool check(int mid)
{
	for (int i = 0; i <= 2 * N; i++) c[i] = 0;
	sum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		sum[i] = (a[i] >= mid) ? 1 : -1;
		sum[i] += sum[i - 1];
	}
	ll SUM = 0;
	for (int i = 0; i <= N; i++)
	{
		SUM += getsum(N + sum[i]);
		add(N + sum[i]);
	}
	return SUM >= ((N + 1) * N / (ll)4);
}
int main()
{
	cin >> N;
	int L; int R; L = 0; R = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i]; R = max(R, a[i]);
	}

	while (L <= R)
	{
		int mid = (L + R) >> 1;
		if (check(mid) == true) L = mid + 1;
		else R = mid - 1;
	}
	cout << R << endl;
	return 0;
}