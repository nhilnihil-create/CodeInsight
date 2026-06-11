#include <bits/stdc++.h>
typedef long long lint;

#define PI acos(-1)
#define INF64 1LL << 62
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<lint, lint> P;

bool pairCompare(const P &value1, const P &value2)
{
	return value1.first < value2.first;
}

void execute()
{
	int N, K;
	lint input_x, input_y;
	lint right, left, top, bottom;
	lint ans = INF64;
	int count;
	cin >> N >> K;
	vector<P> point(N);
	vector<lint> y(N);

	for (int i = 0; i < N; i++)
	{
		cin >> input_x >> input_y;
		point[i].first = input_x;
		point[i].second = input_y;
		y[i] = input_y;
	}
	sort(all(point), pairCompare);
	sort(all(y));

	for (int i = 0; i < N - K + 1; i++)
	{
		for (int j = i + K - 1; j < N; j++)
		{
			for (int k = 0; k < N - K + 1; k++)
			{
				for (int l = k + K - 1; l < N; l++)
				{
					right = point[i].first;
					left = point[j].first;
					top = y[k];
					bottom = y[l];
					count = 0;
					for (int m = i; m <= j; m++)
					{
						if (right <= point[m].first && point[m].first <= left &&
							top <= point[m].second && point[m].second <= bottom)
							count++;
					}
					if (count == K)
						ans = min(ans, (left - right) * (bottom - top));
					//cout << (left - right) * (bottom - top) << " " << top << " " << bottom << " " << left << " " << right << endl;
				}
			}
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