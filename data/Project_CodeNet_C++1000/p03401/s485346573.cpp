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
	int N;
	cin >> N;
	vector<lint> data(N + 2);
	lint sum = 0;

	data[0] = 0;
	data[N + 1] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> data[i + 1];
		sum += abs(data[i + 1] - data[i]);
	}
	sum += abs(data[N]);

	for (int i = 1; i <= N; i++)
	{
		int out = sum;
		out -= abs(data[i] - data[i - 1]);
		out -= abs(data[i] - data[i + 1]);
		out += abs(data[i + 1] - data[i - 1]);
		cout << out << endl;
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