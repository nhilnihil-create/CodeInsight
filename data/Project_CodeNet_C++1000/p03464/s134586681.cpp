#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll b[maxn], l[maxn], r[maxn];
void calc(int i)
{
	l[i] = (l[i + 1] + b[i] - 1) / b[i] * b[i];
	r[i] = r[i + 1] / b[i] * b[i];
	if(l[i] > r[i])
	{
		puts("-1");
		exit(0);
	}
	r[i] += b[i] - 1;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> b[i];
	l[n + 1] = r[n + 1] = 2;
	for(int i = n; i; --i) 
		calc(i);
	cout << l[1] << ' ' << r[1] << endl;
	return 0;
}