#include <bits/stdc++.h>

#define INF64 1LL << 60;
#define INF32 1 << 29;

using namespace std;

void execute()
{
	string S;
	int len, half;
	int base;
	int even_num;
	int ans;

	cin >> S;
	len = (int)S.size();
	ans = half = len / 2;
	even_num = len % 2 == 0 ? 1 : 0;
	base = S[half];

	for (int i = 0; i <= half + even_num; i++)
	{
		if (base != S[half - i - even_num] || base != S[half + i])
			break;
		ans++;
	}

	cout << ans << endl;
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