#include <bits/stdc++.h>

int query(int);

int main()
{
	int N;
	scanf("%d", &N);
	int upper{N}, lower{}, gender{query(0)};
	if (gender == 2) return 0;
	while (true)
	{
		int mid{(upper + lower) >> 1};
		int input{query(mid)};
		if (input == 2) break;
		if ((gender + input) % 2 == (mid - lower) % 2)
		{
			lower = mid;
			gender = input;
		}
		else
			upper = mid;
	}

	return 0;
}

int query(int output)
{
	printf("%d\n", output);
	fflush(stdout);
	std::string s;
	std::cin >> s;
	if (s == "Male") return 0;
	else if (s == "Female") return 1;
	else return 2;
}