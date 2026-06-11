#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int A, B;
	cin >> A >> B;
	vector<vector<bool>> grid(100, vector<bool>(100));

	A--;
	B--;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i < 50)
				grid[i][j] = true;
			else
				grid[i][j] = false;
		}
	}

	for (int i = 0; i < 50; i += 2)
	{
		for (int j = 0; j < 100; j += 2)
		{
			if (0 < A)
			{
				grid[i][j] = false;
				A--;
			}
		}
	}

	for (int i = 99; 50 <= i; i -= 2)
	{
		for (int j = 0; j < 100; j += 2)
		{
			if (0 < B)
			{
				grid[i][j] = true;
				B--;
			}
		}
	}

	cout << "100 100" << endl;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cout << (grid[i][j] ? "#" : ".");
		}
		cout << endl;
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