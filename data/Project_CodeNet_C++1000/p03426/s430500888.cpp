#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define LIMIT(d_in, d_min, d_max) max(d_min, min(d_max, d_in))
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int H, W, D;
	cin >> H >> W >> D;
	vector<int> Vi(H * W);
	vector<int> Vj(H * W);
	vector<int> cum(H * W, 0);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int tmp;
			cin >> tmp;
			tmp--;
			Vi[tmp] = i;
			Vj[tmp] = j;
		}
	}

	for (int i = 0; i + D < H * W; i++)
	{
		cum[i + D] = cum[i] + abs(Vi[i] - Vi[i + D]) + abs(Vj[i] - Vj[i + D]);
	}

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int left, right;
		cin >> left >> right;
		left--;
		right--;
		cout << cum[right] - cum[left] << endl;
	}
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