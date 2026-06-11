#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N;
	cin >> N;
	int all = pow(3, N);
	int sub = 1;
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		if (A%2 == 0)
			sub *= 2;
	}
	cout << all - sub << endl;
}

