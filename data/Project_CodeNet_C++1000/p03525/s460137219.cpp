#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 55;
int D[MAX_N],cnt[13],temp[MAX_N];

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		cin >> D[i];
	}

	int ans = 0;
	if (N >= 24)
	{
		cout << "0" << endl;
		return 0;
	}
	else if (N >= 12)
	{
		cnt[0]++;
		rep(i,N)
		{
			cnt[D[i]]++;
		}
		for (int i = 1; i <= 11; ++i)
		{
			if (cnt[i] >= 3)
			{
				cout << "0" << endl;
				return 0;
			}
		}
		if (cnt[0] >= 2 || cnt[12] >= 2)
		{
			cout << "0" << endl;
			return 0;
		}
		cout << "1" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < (1 << N); ++i)
		{
			rep(j,N)
			{
				if ((1 << j) & i)
				{
					temp[j] = 24 - D[j];
				}
				else
				{
					temp[j] = D[j];
				}
			}
			temp[N] = 0;
			int s = 100;
			for (int j = 0; j <= N; ++j)
			{
				for (int k = j+1; k <= N; ++k)
				{
					int t = abs(temp[j] - temp[k]);
					s = min(s,min(t,24-t));
				}
			}
			ans = max(ans,s);
		}
	}
	cout << ans << endl;
	return 0;
}