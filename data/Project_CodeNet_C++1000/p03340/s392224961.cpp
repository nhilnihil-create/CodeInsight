#include <bits/stdc++.h>
typedef long long lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int N;
	lint ans = 0;
	lint current = 0;
	cin >> N;

	vector<lint> a(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	int left = 0, right = 0;

	current = 0;

	for (left = 0; left < N; left++)
	{
		if (right < left)
			current += a[right++];

		for (; right < N; right++)
		{
			if (current & a[right])
			{
				break;
			}
			current += a[right];
		}
		ans += right - left;
		if (left == right)
		{
			right++;
		}
		else
		{
			current -= a[left];
		}
	}

	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}