#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[55];

int main()
{
	int N;
	cin >> N;
	cin >> a[0];
	P M = P(a[0],0), m = P(a[0],0);
	for (int i = 1; i < N; ++i)
	{
		cin >> a[i];
		if (a[i] > M.first) M = P(a[i],i);
		if (a[i] < m.first) m = P(a[i],i);
	}
	cout << 2*N - 2 << endl;
	if (abs(m.first) < abs(M.first))
	{
		rep(i,N)
		{
			if (i != M.second) cout << M.second+1 << " " << i+1 << endl;
		}
		rep(i,N-1)
		{
			cout << i+1 << " " << i+2 << endl;
		}
	}
	else
	{
		rep(i,N)
		{
			if (i != m.second) cout << m.second+1 << " " << i+1 << endl;
		}
		rep(i,N-1)
		{
			cout << N-i << " " << N-i-1 << endl;
		}
	}
	return 0;
}