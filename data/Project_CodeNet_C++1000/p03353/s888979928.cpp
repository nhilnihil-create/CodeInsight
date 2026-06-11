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
	string input;
	int k;
	cin >> input;
	cin >> k;
	set<string> data;
	int len = input.size();

	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= min(5, len - i); j++)
		{
			data.insert(input.substr(i, j));
		}
	}
	int count = 0;
	for (auto out : data)
	{
		count++;

		if (count < k)
			continue;
		else
		{
			cout << out << endl;
			return;
		}
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