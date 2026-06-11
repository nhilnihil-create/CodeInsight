#include <bits/stdc++.h>
#define INF64 1LL << 60;
#define INF32 1 << 29;

using namespace std;

void execute()
{
	int n;
	int max = -INF32;
	int min = INF32;
	int pos_max = -1, pos_min = -1;
	bool pm;
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (max < tmp)
		{
			max = tmp;
			pos_max = i;
		}
		if (tmp < min)
		{
			min = tmp;
			pos_min = i;
		}
	}

	pm = abs(min) <= abs(max);

	cout << (n * 2 - 1) << endl;
	for (int i = 0; i < n; i++)
	{
		cout << (pm ? pos_max : pos_min) + 1 << " " << i + 1 << endl;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int j = pm ? i : n - 1 - i;
		cout << j + 1 << " " << j + (pm ? 1 : -1) + 1 << endl;
	}

	return;
}

int main()
{
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}