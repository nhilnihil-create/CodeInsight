#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	cout << N*(N-1)/2 - N/2 << endl;
	int d;
	if (N % 2 == 0) d = N + 1;
	else d = N;
	for (int i = 1; i < N; ++i)
	{
		for (int j = i+1; j <= N; ++j)
		{
			if (i+j != d) cout << i << " " << j << endl;
		}
	}
	return 0;
}