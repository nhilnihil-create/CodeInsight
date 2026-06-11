#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read()
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9')
		ch = getchar();
	do {
		ret = ret * 10 + ch - '0';
		ch = getchar();
	} while('0' <= ch && ch <= '9');
	return ret;
}
inline void write(int x) // x > 0 (x != 0) ***
{
	if(!x)
		return ;
	write(x / 10);
	putchar(x % 10 + '0');
}
#define maxn 100100
int n;
int a[1010][1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int k = 0;
	for( ; ; k ++)
	{
		if(k * (k + 1) > n * 2)
			return cout << "No\n", 0;
		else if(k * (k + 1) == n * 2)
			break;
	}
	int cur = 0;
	for(int i = 1; i <= k + 1; i ++)
	{
		for(int j = 1; j < i; j ++)
			a[i][j] = a[j][i - 1];
		int rem = k - i + 1;
		for(int j = 1; j <= rem; j ++)
			a[i][i + j - 1] = cur + j;
		cur += rem;
	}
	cout << "Yes\n";
	cout << k + 1 << endl;
	for(int i = 1; i <= k + 1; i ++)
	{
		cout << k << ' ';
		for(int j = 1; j <= k; j ++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
