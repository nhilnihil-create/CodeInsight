#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

void	putbit(int n)
{
	if (!n)
		return ;
	else
	{
		int b = n % 2; 
		if (b < 0)
			b += 2;
		n -= b;
		putbit(n/-2);
		b ? cout << 1 : cout << 0;
	}

}

int		main(void)
{
	int n;
	cin >> n;
	if (n)
		putbit(n);
	else
		cout << 0;
	cout << endl;
}

