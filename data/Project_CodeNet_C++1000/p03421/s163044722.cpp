#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int cnt[MAXN];

int N, A, B;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> A >> B;
	if (A + B - 1 > N || (ll)A * B < N)
		cout << -1 << endl;
	else
	{
		int tot = N;
		for (int i = 1; i <= A; i++)
			--tot;
		cnt[1] += B - 1, tot -= B - 1;
		for (int i = 2; i <= A && cnt; i++)
		{
			if (tot >= B - 1)
				cnt[i] += B - 1, tot -= B - 1;
			else
				cnt[i] += tot, tot = 0;
		}
		for (int i = 1; i <= A; i++)
			cout << N - A + i << " ";
		int cur = 0;
		for (int i = 1; i <= A; i++)
		{
			for (int j = 1; j <= cnt[i]; j++)
				cout << cur + cnt[i] - j + 1 << " ";
			cur += cnt[i];
		}
		cout << endl;
	}
	return 0;
}
