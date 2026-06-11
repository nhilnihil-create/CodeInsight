#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int N;

int main()
{
	cin >> N;
	if (N == 0)
		cout << 0 << endl;
	int mod = -2;
	stack<int> s;
	while (N != 0)
	{
		if (N % mod == -1)
			s.push(1), N = (N - 1) / mod;
		else
			s.push(N % mod), N = (N - N % mod) / mod;
	}
	while (s.size() > 0)
		cout << s.top(), s.pop(); cout << endl;
}


