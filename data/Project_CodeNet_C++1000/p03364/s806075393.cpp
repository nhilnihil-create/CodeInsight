#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 305;
char S[MAX_N][MAX_N];

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		rep(j,N)
		{
			cin >> S[i][j];
		}
	}
	int ans = 0;
	for (int i = -N+1; i <= N-1; ++i)
	{
		bool flag = true;
		for (int a = 0; a < N; ++a)
		{
			for (int b = 0; b < N; ++b)
			{
				int c = (b + N - i) % N;
				int d = (a + N + i) % N;
				if (S[a][b] != S[c][d]) flag = false;
			}
		}
		//cout << i << " " <<  flag << endl;
		if (flag) ans += N - abs(i);
	}
	cout << ans << endl;
	return 0;
}