#include <bits/stdc++.h>

int n;
std::vector<std::pair<long long, int>> a;
bool possible(const int);
bool adjust(std::vector<std::pair<long long, int>>&, const int);

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		scanf("%lld", &tmp);
		if (!i || a.back().first != tmp)
			a.push_back({tmp, 1});
		else
			a.back().second++;
	}

	int left{0}, right{n};
	while (left + 1 < right)
	{
		int mid{(left + right) / 2};
		if (possible(mid)) right = mid;
		else left = mid;
	}
	printf("%d\n", right);

	return 0;
}

bool possible(const int type)
{
	long long pre_length{};
	std::vector<std::pair<long long, int>> s;
	for (auto& e: a)
	{
		if (pre_length < e.first)
			s.push_back({e.first - pre_length, e.second - 1});
		else
		{
			if (!adjust(s, type)) return false;
			while (pre_length - s.back().first >= e.first)
			{
				pre_length -= s.back().first;
				s.pop_back();
			}
			if (pre_length == e.first)
				s.back().second += e.second;
			else
			{
				for (long long i{}; i < pre_length - e.first && s.back().second; i++)
					s.back().second /= type;
				s.back().first -= pre_length - e.first;
				s.back().second += e.second;
			}
		}
		pre_length = e.first;
	}
	return adjust(s, type);
}

bool adjust(std::vector<std::pair<long long, int>>& s, const int type)
{
	for (auto i{s.end() - 1}; i != s.begin(); i--)
	{
		long long tmp{1};
		for (int j{}; tmp <= i->second && j < i->first; j++)
			tmp *= type;
		if (i->second < tmp) continue;
		(i - 1)->second += i->second / tmp;
		i->second %= tmp;
	}
	long long tmp{1};
	for (int i{}; tmp <= s.front().second && i < s.front().first; i++)
		tmp *= type;
	if (s.front().second < tmp) return true;
	return false;
}